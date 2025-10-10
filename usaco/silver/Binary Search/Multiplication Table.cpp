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

	auto da = [&](ll m) {
		ll res = 0;
		for (int i = 1; i <= n; ++i) {
			res += min((ll)n, m / i);
		}
		return res > (ll)n * n / 2;
	};

	ll l = 1, r = (ll)n * n, res;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;	
		} else {
			l = m+1;
		}
	}
	cout << l << endl;

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
