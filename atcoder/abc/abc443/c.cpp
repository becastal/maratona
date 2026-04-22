#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, t; cin >> n >> t;

	int res = 0;
	for (int i = 0, x, r = 0; i < n; i++) {
		cin >> x;

		if (r < x) {
			r = x + 100;
			res += min(r, t) - x;
		}
	}
	cout << t - res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

