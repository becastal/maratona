#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int res = 0, mx = LLONG_MIN;
	for (int i = 0, x; i < 7; i++) {
		cin >> x;
		res += -x;
		mx = max(mx, x);
	}
	cout << res + 2 * mx << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

