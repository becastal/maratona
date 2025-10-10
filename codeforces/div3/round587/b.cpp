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
	int n; cin >> n;

	vector<pair<int, int>> v(n);
	int id_ = 1;
	for (auto& [i, id] : v) cin >> i, id = id_++;
	sort(v.rbegin(), v.rend());

	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += (ll)i * v[i].f + 1;
	}
	cout << res << endl;
	for (auto [i, id] : v) cout << id << ' '; cout << endl;

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
