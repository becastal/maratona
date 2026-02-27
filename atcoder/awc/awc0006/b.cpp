#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, t, res = 0; cin >> n >> k >> t;
	for (int i = 0, d, r; i < n; i++) {
		cin >> d >> r;
		if (r >= k * d) {
			res += r;
		}
	}
	cout << (res >= t ? "Yes" : "No") << endl;

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

