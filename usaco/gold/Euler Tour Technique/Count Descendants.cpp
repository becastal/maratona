#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct Bit {
	int n;
	vector<int> F;
	Bit (int n_) : n(n_), F(n_ + 1) {};
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) F[i] += x;
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) res += F[i];
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);

	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[i].push_back(p);
		G[p].push_back(i);
	}

	int t = 0;
	vector<int> L(n), R(n), D(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			dfs(v, u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	vector<vector<int>> U(n);
	for (int u = 0; u < n; u++) {
		U[D[u]].push_back(u);
	}

	int q; cin >> q;
	vector<vector<array<int, 2>>> Q(n);
	for (int i = 0, u, d; i < q; i++) {
		cin >> u >> d; u--;
		Q[d].push_back({u, i});
	}

	Bit bit(n);
	vector<int> res(q);
	for (int d = 0; d < n; d++) {
		for (int u : U[d]) {
			bit.update(L[u], +1);		
		}

		for (auto [u, id] : Q[d]) {
			res[id] = bit.query(L[u], R[u]);	
		}

		for (int u : U[d]) {
			bit.update(L[u], -1);		
		}
	}
	for (int i : res) cout << i << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
