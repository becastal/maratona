#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, l, r, t; cin >> n >> l >> r >> t;
	array<int, 3> res = {LLONG_MAX, LLONG_MAX, LONG_MAX};
	for (int i = 0, p, s; i < n; i++) { 
		cin >> p >> s;
		if (l <= p and p <= r and s >= t) {
			res = min(res, array<int, 3>{p, -s, i + 1});
		}
	}
	//cout << res[0] << ' ' << res[1] << ' ' << res[2] << endl;
	if (res[2] == LLONG_MAX) res[2] = -1;
	cout << res[2] << endl;

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

