#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	for (int i = 0, a, v = 0, lig = 0; i < n; i++) {
		cin >> a;

		if (a == 1) {
			v++;	
		} else if (a == 2) {
			v = max(0LL, v - 1);
		} else if (a == 3) {
			lig ^= 1;	
		}

		cout << (lig and v >= 3 ? "Yes" : "No") << endl;
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

