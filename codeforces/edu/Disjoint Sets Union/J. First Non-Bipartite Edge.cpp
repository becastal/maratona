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

struct dsu {
	vector<int> id, sz, bip, c;

	dsu(int n) : id(n), sz(n, 1), bip(n, 1), c(n) { 
		iota(id.begin(), id.end(), 0); 
	}

	int find(int a) { return a == id[a] ? a : find(id[a]); }
	int color(int a) { return a == id[a] ? c[a] : c[a] ^ color(id[a]); }

	void unite(int a, int b) {
		bool change = color(a) == color(b);
		a = find(a), b = find(b);
		if (a == b) {
			if (change) bip[a] = 0;
			return;
		}
		
		if (sz[a] < sz[b]) swap(a, b);
		if (change) c[b] = 1;
		sz[a] += sz[b], id[b] = a, bip[a] &= bip[b];
	}
};

int solve() {
	int n, m; cin >> n >> m;
	dsu D(n);

	vector<pair<int, int>> E(m);
	for (auto& [a, b] : E) cin >> a >> b, a--, b--;

	for (int i = 0; i < m; i++) {
		auto [a, b] = E[i];

		D.unite(a, b);
		if (!D.bip[D.find(a)] or !D.bip[D.find(b)]) return cout << i+1 << endl, 0;
	}
	cout << -1 << endl;

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
