#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int a, b; cin >> a >> b;

	if (20 <= a and a <= 30 and b >= 50) return cout << "HABITAVEL" << endl, 0;
	if (0 <= a and a <= 50 and b >= 30) return cout << "ADAPTAVEL" << endl, 0;
	cout << "HOSTIL" << endl;

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

