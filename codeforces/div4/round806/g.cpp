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

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<ll>> dp(n+1, vector<ll>(32, -LINF));
	dp[0][0] = 0;

	ll res = -LINF;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 31; j++) {
			dp[i][j] = max({dp[i][j], dp[i-1][j] - k + (v[i-1] >> j), (j ? dp[i-1][j-1] + (v[i-1] >> j) : -LINF)});
			res = max(res, dp[i][j]);
		}
	}

	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
