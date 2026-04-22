#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int t, x; cin >> t >> x;
	for (int i = 0, ult = 0, a; i <= t; i++) {
		cin >> a;
		if (!i or abs(a - ult) >= x) {
			cout << i << ' ' << a << endl;
			ult = a;
		}
	}

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

