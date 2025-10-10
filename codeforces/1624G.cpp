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

struct DSU {
	int cc;
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1), cc(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		cc--;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<array<int, 3>> E(m);
	for (auto& [u, v, w] : E) cin >> u >> v >> w, u--, v--;

	auto ok = [&](int x) {
		DSU dsu(n);
		for (auto [u, v, w] : E) {
			if ((w & x) == w) dsu.merge(u, v);
		}
		return dsu.cc == 1;
	};

	int res = 0;
	for (int i = 0; i < 30; i++) {
		int agr = 0;
		if (ok(res)) break;
		for (int j = 0; j < 30; j++) {
			agr |= (1 << j);
			if (ok(agr | res)) {
				res |= (1 << j);
				break;
			}
		}
	}

	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
