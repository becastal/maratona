#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<int> id, sz;

	Dsu(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};

int solve() {
	int n; cin >> n;

	vector<int> A(n);
	for (int& i : A) cin >> i;	
	vector<vector<int>> G(n);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	queue<int> Q;
	vector<map<int, int>> M(n);
	for (int u = 0; u < n; u++) {
		M[u][A[u]] = 1;
		if (G[u].size() == 1) Q.push(u);
	}

	Dsu dsu(n);
	vector<int> vis(n);
	while (Q.size()) {
		int u = Q.front(); Q.pop();
		cout << u << endl;
		vis[u] = 1;
		for (int v : G[u]) if (vis[v]) {
			for (auto [a, b] : M[v]) {
				int a_ = gcd(a, A[u]);
				M[u][a_] += b;
			}
			dsu.merge(u, v);
		} else Q.push(v);
	}

	for (auto [a, b] : M[n-1]) {
		cout << a << ' ' << b << endl;
	}

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

