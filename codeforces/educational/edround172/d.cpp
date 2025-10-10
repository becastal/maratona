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
typedef pair<int, int> ii;

void solve() {
	int n; cin >> n;

	vector<ii> v(n);
	map<ii, int> f;

	for (auto& [l, r] : v) cin >> l >> r, f[ii(l, r)]++;

	vector<int> res(n, 0);
	for (int k = 0; k < 2; k++) {
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);

		sort(ord.begin(), ord.end(), [&](int i, int j) {
			if (v[i].f != v[j].f) {
				return v[i].f < v[j].f;
			}
			return v[i].s > v[j].s;
		});

		set<int> lim;
		for (int i : ord) {
			auto it = lim.lower_bound(v[i].s);

			if (it != lim.end()) {
				res[i] += *it - v[i].s;
			}

			lim.insert(v[i].s);
		}

		for (auto& [l, r] : v) {
			l = -l, r = -r;
			swap(l, r);
		}
	}

	for (int i = 0; i < n; i++) {
		if (f[v[i]] > 1) cout << 0 << endl;
		else cout << res[i] << endl;
	}
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
