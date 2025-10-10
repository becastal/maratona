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
	ll n; cin >> n;

	auto da = [&](ll m) {

		ll res = 0;
		for (ll p = 5; p <= m; p *= 5) {
			res += m / p;
		}

		return res;
	};

	ll l = 1, r = (ll)1e12 + 10, res = -1;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m) >= n) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	if (res != -1 and da(res) == n) {
		cout << res << endl;
	} else {
		cout << -1 << endl;
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
