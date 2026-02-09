#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	auto cbrt_ = [](ll x) {
		ll l = 0, r = x;
		while (l < r) {
			ll m = l + (r - l + 1) / 2;

			if ((m * m * m) <= x) {
				l = m;
			} else {
				r = m-1;
			}
		}
		return l;
	};

	ll n; cin >> n;
	for (ll i = 1; i <= (3e6+10); i++) {
		ll ii = i*i*i;

		ll x = cbrt_(n + ii);
		if (x * x * x == n + ii) {
			return cout << x << ' ' << i << endl, 0;
		}
	}
	cout << -1 << endl;
    
    return(0);
}
