#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n;
	vector<int> id, sz;

	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int u) {
		return (u == id[u] ? u : id[u] = find(id[u]));
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = u;
		return 1;
	}

	int tam(int u) {
		return sz[find(u)];
	}
};

int solve() {
	int n, m, t; cin >> n >> m >> t;
	vector<vector<int>> A(n, vector<int>(m));

	auto id = [m](int i, int j) {
		return i * m + j;	
	};

	vector<array<int, 3>> E;
	const vector<array<int, 2>> movs = { {-1, 0}, {0, -1} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];	

			for (auto [di, dj] : movs) {
				int i_ = i + di, j_ = j + dj;
				if (i_ < 0 or j_ < 0 or i_ >= n or j_ >= m) continue;
				int a = id(i, j), b = id(i_, j_), w = abs(A[i][j] - A[i_][j_]);
				E.push_back({w, a, b});
			}
		}
	}

	sort(all(E));
	int mm = (int)E.size();

	vector<int> U, L, R, Res;
	vector<vector<int>> Mids(mm);
	for (int i = 0, x; i < n * m; i++) {
		cin >> x;
		if (x) {
			U.push_back(i);
			L.push_back(0);
			R.push_back(mm - 1);
			Res.push_back(0);
		}
	}

	int nn = (int)U.size();
	for (int rep = 0, lim = __lg(mm) + 3; rep < lim; rep++) {
		Dsu dsu(n * m);

		for (int i = 0; i < nn; i++) {
			if (L[i] <= R[i]) {
				int mid = L[i] + (R[i] - L[i]) / 2;
				Mids[mid].push_back(i);
			}
		}

		for (int mid = 0; mid < mm; mid++) {
			auto [w, a, b] = E[mid];
			dsu.merge(a, b);
			
			for (int i : Mids[mid]) {
				if (dsu.tam(U[i]) >= t) {
					R[i] = mid - 1;
					Res[i] = mid;
				} else {
					L[i] = mid + 1;
				}
			}
			Mids[mid].clear();
		}
	}

	int res = 0;
	for (int i = 0; i < nn; i++) {
		res += E[Res[i]][0];	
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("skilevel");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

