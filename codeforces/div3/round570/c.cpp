#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		ll k, n, a, b; cin >> k >> n >> a >> b; 

		if (b * n >= k) {
			cout << -1 << endl;
			continue;
		}

		ll l = 0, r = n, res = -1;
        while (l <= r) {
            ll m = l + (r - l) / 2;

            if (m * a + (n - m) * b < k) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

		cout << res << endl;
	}
    
    return(0);
}
