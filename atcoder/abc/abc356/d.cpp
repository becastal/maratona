#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

000
001
010
011
100
101
110
111
0
0
0
0
1
1
1

*/

const int mod = 998244353;
int solve() {
	int n, m; cin >> n >> m; n++;

	int res = 0;
	for (int b = 0, per = 1; b <= 60; b++, per <<= 1) if (m >> b & 1) {
		res = (res + n / (per << 1) * per % mod) % mod;
		res = (res + max(0LL, n % (per << 1) - per)) % mod;
	}
	cout << res << endl;

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

