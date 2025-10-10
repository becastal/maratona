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

int solve() {
	int n, m; cin >> n >> m;
	vector<pair<vector<int>, int>> a(n);

	for (int i = 0; i < n; i++) {
		a[i].s = i;
		a[i].f = vector<int>(m);
		for (int& j : a[i].f) cin >> j;
		sort(a[i].f.begin(), a[i].f.end());
	}
	sort(a.begin(), a.end());

	vector<int> b;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b.push_back(a[j].f[i]);
		}
	}

	if (!is_sorted(b.begin(), b.end())) return cout << -1 << endl, 0;
	for (auto [vi, pi] : a) cout << pi + 1 << ' '; cout << endl;

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
