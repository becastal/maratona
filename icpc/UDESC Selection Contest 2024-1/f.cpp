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

int solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> s(n), e(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i];
	}

	vector<ll> dp(n+1, -LINF);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		dp[i+1] = max(dp[i+1], dp[i] + ll(e[i] - s[i]));
		dp[min(i+k, n)] = max(dp[min(i+k, n)], dp[i] - x);
	}
	cout << max(0LL, dp[n]) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
