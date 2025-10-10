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

ll cartas(ll m) {
	ll a = (0 + (m - 1)) * m / 2;
	ll b = (2 + (2*m)) * m / 2;
	return a + b;
}

int solve() {

	ll c; cin >> c;
	ll l = 1, r = (ll)1e9 + 10;

	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (cartas(m) > c) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << l-1 << endl;

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
