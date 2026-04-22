#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int a, b, c, m; cin >> a >> b >> c >> m;

	int lcm_ab = lcm(a, b), lcm_ac = lcm(a, c), lcm_bc = lcm(b, c), lcm_abc = lcm(a, lcm(b, c));
	cout << 6 * (m / a) - 3 * (m / lcm_ab) - 3 * (m / lcm_ac) + 2 * (m / lcm_abc) << ' ';
	cout << 6 * (m / b) - 3 * (m / lcm_ab) - 3 * (m / lcm_bc) + 2 * (m / lcm_abc) << ' ';
	cout << 6 * (m / c) - 3 * (m / lcm_ac) - 3 * (m / lcm_bc) + 2 * (m / lcm_abc) << endl;

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

