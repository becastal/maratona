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

	int n; cin >> n;
	vector<int> c(n), a(n);

	for (int i = 1; i < n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) cin >> a[i];

	vector<int> dp(n, INF);

	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i-1] + !!a[i];

		for (int j = i+1; j < n; j++) {
			if (i >= j - c[j]) {
				dp[j] = min(dp[j], dp[i] + 1);
			}
		}
	}

	int res = INF;
	for (int i = 1; i < n; i++) if (a[i]) res = min(res, dp[i]);
	cout << res << endl;
    
    return(0);
}
