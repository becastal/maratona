#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

// Kuhn
//
// Computa matching maximo em grafo bipartido
// 'n' e 'm' sao quantos vertices tem em cada particao
// chamar add(i, j) para add aresta entre o cara i
// da particao A, e o cara j da particao B
// (entao i < n, j < m)
// Para recuperar o matching, basta olhar 'ma' e 'mb'
// 'recover' recupera o min vertex cover como um par de
// {caras da particao A, caras da particao B}
//
// O(|V| * |E|)
// Na pratica, parece rodar tao rapido quanto o Dinitz

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;

	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].push_back(b); }

	bool dfs(int i) {
		vis[i] = 1;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1 or dfs(mb[j])) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	int matching() {
		int ret = 0, aum = 1;
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (aum) {
			for (int j = 0; j < m; j++) vis[n+j] = 0;
			aum = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
		}
		return ret;
	}
};

pair<vector<int>, vector<int>> recover(kuhn& K) {
	K.matching();
	int n = K.n, m = K.m;
	for (int i = 0; i < n+m; i++) K.vis[i] = 0;
	for (int i = 0; i < n; i++) if (K.ma[i] == -1) K.dfs(i);
	vector<int> ca, cb;
	for (int i = 0; i < n; i++) if (!K.vis[i]) ca.push_back(i);
	for (int i = 0; i < m; i++) if (K.vis[n+i]) cb.push_back(i);
	return {ca, cb};
}

int solve() {
	int n, a, b; cin >> n >> a >> b;
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}
	
	vector<array<int, 2>> Movs = {
		{-a, -b},
		{-a, +b},
		{+a, -b},
		{+a, +b},
		{-b, -a},
		{-b, +a},
		{+b, -a},
		{+b, +a},
	};

	vector<vector<int>> G(n * n);

	for (int ui = 0; ui < n; ui++) {
		for (int uj = 0; uj < n; uj++) if (A[ui][uj] == '.'){
			for (auto [di, dj] : Movs) {
				int vi = ui + di, vj = uj + dj;
				if (vi < 0 or vj < 0 or vi >= n or vj >= n or A[vi][vj] == '#') continue;
				G[ui * n + uj].push_back(vi * n + vj);
				G[vi * n + vj].push_back(ui * n + uj);
			}
		}
	}

	vector<int> Cor(n * n, -1);
	vector<vector<int>> P(2);
	function<int(int, int)> dfs = [&](int u, int c) {
		P[Cor[u] = c].push_back(u);

		for (int v : G[u]) {
			if (Cor[v] == -1) {
				if (!dfs(v, c ^ 1)) return 0;
			} else if (Cor[u] == Cor[v]) return 0;
		}
		return 1;
	};

	for (int u = 0; u < n * n; u++) if (A[u / n][u % n] == '.' and Cor[u] == -1) {
		assert(dfs(u, 0));
	}
	
	vector<vector<int>> Id(2, vector<int>(n * n, -1));
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < (int)P[j].size(); i++) {
			Id[j][P[j][i]] = i;
		}
	}

	kuhn M((int)P[0].size(), (int)P[1].size());
	for (int u : P[0]) {
		for (int v : G[u]) {
			M.add(Id[0][u], Id[1][v]);
		}
	}

	vector<string> R = A;
	auto [Sa, Sb] = recover(M);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (R[i][j] == '.') {
			R[i][j] = 'o';
		}
	}
	for (int i : Sa) { 
		int u = P[0][i];
		int ui = u / n, uj = u % n;
		R[ui][uj] = '.';
	}
	for (int i : Sb) { 
		int u = P[1][i];
		int ui = u / n, uj = u % n;
		R[ui][uj] = '.';
	}

	for (int i = 0; i < n; i++) {
		cout << R[i] << endl;
	}
	
	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

