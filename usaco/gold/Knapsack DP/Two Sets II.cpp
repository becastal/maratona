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
	// de quantos jeitos eu consigo somar S / 2;

	const int mod = 1e9 + 7;
	int n; cin >> n;
	int s = (n + 1) * n / 2;
	if (s & 1) return cout << 0 << endl, 0;

	s /= 2;
	vector dp(n+1, vector<int>(s+1));

	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = dp[i-1][j];	
			int sobra = j - i;
			if (sobra >= 0) {
				dp[i][j] = (dp[i][j] + dp[i-1][sobra]) % mod;
			}
		}
	}

	cout << dp[n-1][s] << endl;

    return(0);
}
