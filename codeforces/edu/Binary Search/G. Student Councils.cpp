#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, k; cin >> k >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	auto da = [&](ll m) {
		ll s = 0;
		for (ll i : A) s += min(m, i);
		return s >= m * k;
	};

	ll l = 0, r = (ll)1e12+10, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			l = m + 1;
			res = m;
		} else {
			r = m - 1;
		}
	}
	cout << res << endl;

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
