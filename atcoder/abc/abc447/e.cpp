#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	vector<int> id, sz;
	int cc;

	Dsu(int n) : id(n), sz(n, 1), cc(n) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
		cc--;
	}
};

const int mod = 998244353;
int solve() {
	int n, m; cin >> n >> m;

	vector<array<int, 2>> E(m);
	for (auto& [u, v] : E) {
		cin >> u >> v; u--, v--;
	}

	Dsu dsu(n);
	int p = m-1;
	for (; p >= 0 and dsu.cc != 2; p--) {
		auto [u, v] = E[p];
		dsu.merge(u, v);
		if (dsu.cc == 2) {
			break;
		}
	}

	vector<int> P(m + 10, 1);
	for (int i = 1; i < m + 10; i++) {
		P[i] = P[i-1] * 2 % mod;	
	}

	int res = 0;
	for (; p >= 0; p--) {
		auto [u, v] = E[p]; 
		if (dsu.find(u) == dsu.find(v)) {
			continue;
		}
		res += P[(p + 1)];
		if (res >= mod) {
			res -= mod;
		}
	}
	cout << res << endl;

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

