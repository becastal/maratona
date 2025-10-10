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

	const int mod = 998244353;
	int q, k; cin >> q >> k;
	vector<int> dp(k+1, 0);

	dp[0] = 1;
	for (int i = 0, x; i < q; i++) {
		char c; cin >> c >> x;
		if (c == '+') {
			for (int j = k; j >= x; j--) {
				dp[j] = (dp[j] + dp[j-x]) % mod;
			}
		} else {
			for (int j = x; j <= k; j++) {
				dp[j] = (dp[j] + mod - dp[j-x]) % mod;
			}
		}
		cout << dp[k] << endl;
	}

    return(0);
}
