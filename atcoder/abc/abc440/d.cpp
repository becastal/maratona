#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector<ll> A(n);

	for (ll& i : A) {
		cin >> i;
	}
	sort(all(A));

	while (q--) {
		ll a, b; cin >> b >> a;
		ll l = b, r = ll(1e13+10), res = -1;
		while (l <= r) {
			ll m = l + (r - l) / 2;

			if ((m - b + 1) - ll(upper_bound(all(A), m) - lower_bound(all(A), b)) >= a) {
				res = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << res << endl;
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

