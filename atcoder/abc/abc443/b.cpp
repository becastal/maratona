#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;

	int s = (1 + (n - 1)) * (n - 1) / 2;
	int l = 0, r = 1e9, res = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if ((1 + mid) * mid / 2 - s >= k) {
			r = mid - 1;
			res = mid;	
		} else {
			l = mid + 1;
		}
	}
	cout << res - n << endl;

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

