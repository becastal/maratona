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

const int mod = 998244353;

int main()
{
    _;

	int q, k; cin >> q >> k;
	vector<int> dp(5005, 0);
    
	dp[0] = 1;
	while (q--) {
		char c; int x;
		cin >> c >> x;

		if (c == '+') {
			for (int i = k; i >= x; i--) {
				dp[i] = (dp[i] + dp[i - x]) % mod;
			}
		} else {
			for (int i = x; i <= k; i++) {
				dp[i] += mod - dp[i - x];
				dp[i] %= mod;
			}
		}
		cout << dp[k] << endl;
	}

    return(0);
}
