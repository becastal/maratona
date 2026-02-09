#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

vector<ll> QP;

int solve() {
	ll c, d; cin >> c >> d;

	auto query = [&](ll l, ll r) -> ll {
		if (l > r) return 0LL;
		ll b = floor(sqrtl(r)), a = ceil(sqrtl(l));
		if (a > b) return 0LL;
		return b - a + 1;
	};

	ll b = 1, res = 0;
	while (b <= c) b *= 10;

	while (b / 10 <= c + d) {
		ll xl = (b / 10) - c, xr = b - c - 1;

		xl = max(1LL, xl);
		xr = min(d, xr);
		res += query(c * (b + 1) + xl, c * (b + 1) + xr);
		b *= 10;
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

