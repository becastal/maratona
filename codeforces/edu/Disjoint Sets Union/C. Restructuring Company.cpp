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
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};


int solve() {
	int n, q; cin >> n >> q;
	DSU dsu(n);

	set<int> s;
	for (int i = 0; i < n; i++) s.insert(i);

	while (q--) {
		int tp, a, b; cin >> tp >> a >> b; a--, b--;

		if (tp == 1) {
			dsu.merge(a, b);
		} else if (tp == 2) {
			auto it = s.lower_bound(a);
			while (it != s.end() and *it < b) {
				dsu.merge(*it, *it + 1);
				s.erase(it);
				it = s.lower_bound(a);
			}
		} else if (tp == 3) {
			cout << (dsu.find(a) == dsu.find(b) ? "YES" : "NO") << endl;
		}
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
