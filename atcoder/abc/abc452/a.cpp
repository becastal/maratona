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

	if (a == 1 and b == 7) return cout << "Yes" << endl, 0;
	if (a == 3 and b == 3) return cout << "Yes" << endl, 0;
	if (a == 5 and b == 5) return cout << "Yes" << endl, 0;
	if (a == 7 and b == 7) return cout << "Yes" << endl, 0;
	if (a == 9 and b == 9) return cout << "Yes" << endl, 0;
	cout << "No" << endl;

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

