#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, s; cin >> n >> s;

	int res = 0;
	for (int i = 0; i <= n; i++) {
		if (s - i * 6 <= (n - i) * 5) {
			res = max(res, i * 5 + (n - i) * 6);
		}
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

