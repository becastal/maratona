#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll h, d; cin >> h >> d;
	h--;

	auto triang = [](ll m) {
		return m * (m + 1) / 2;
	};

	auto da = [&](ll m) {
		ll q = d / m, r = d % m;
		ll r2 = m - r;
		ll c = r * triang(q + 1) + r2 * triang(q);
		return h + m - 1 >= c;
	};

	ll l = 1, r = d + 1, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;
			res = m;
		} else {
			l = m+1;
		}
	}
	cout << res + d - 1 << endl;

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

