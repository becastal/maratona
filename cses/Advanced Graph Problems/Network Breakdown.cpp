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
	int c;
	DSU(int n) : id(n), sz(n, 1), c(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		c--;
	}
};

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<array<int, 2>> ed(m), q(k);

	DSU dsu(n);
	for (auto& [u, v] : ed) {
		cin >> u >> v; u--, v--;
		if (u > v) swap(u, v);
	}
	for (auto& [u, v] : q) {
		cin >> u >> v; u--, v--;
		if (u > v) swap(u, v);
	}

	set<array<int, 2>> Q(q.begin(), q.end());
	for (auto p : ed) {
		if (!Q.count(p)) {
			dsu.merge(p[0], p[1]);
		}
	}

	reverse(q.begin(), q.end());
	vector<int> res;
	for (auto [u, v] : q) {
		res.push_back(dsu.c);
		dsu.merge(u, v);
	}
	reverse(res.begin(), res.end());
	for (int i : res) cout << i << ' '; cout << endl;

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
