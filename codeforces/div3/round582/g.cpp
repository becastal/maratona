#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct DSU {
	vector<int> id, sz;
	ll res;
	DSU(int n) : id(n), sz(n, 1), res(0) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		res += (ll)sz[i] * sz[j];
		sz[i] += sz[j], id[j] = i;
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<tuple<int, int, int>> ed(n-1);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}
	sort(ed.begin(), ed.end());

	vector<pair<int, int>> qu(m);
	int id_ = 0;
	for (auto& [qi, id] : qu) {
		cin >> qi; id = id_++;
	}
	sort(qu.begin(), qu.end());

	vector<ll> res(m);
	DSU dsu(n);
	int l = 0;
	for (auto [qi, id] : qu) {
		
		while (l < n-1 and get<0>(ed[l]) <= qi) {
			auto [w, u, v] = ed[l];
			dsu.merge(u, v);
			l++;
		}

		res[id] = dsu.res;
	}

	for (ll i : res) cout << i << ' '; cout << endl;
	
	return(0);
}

int main()
{
    _;

	int t = 1;// cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
