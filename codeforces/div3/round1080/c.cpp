#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, res = 0; cin >> n;
	for (int i = 0, x, ult; i < n; i++) {
		cin >> x;
		if (i and (ult == 7 - x or ult == x)) {
			res++;
			ult = -1000;
		} else ult = x;
	}
	cout << res << endl;

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

