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

	int n, a, b, c; cin >> n >> a >> b >> c;
	vector<int> dp(n+1, -INF);
	dp[0]=0;
	for (int i = 1; i <= n; i++) {
		for (int j : {a, b, c}) {
			if (i - j < 0) continue;
			dp[i] = max(dp[i], dp[i-j] + 1);
		}
	}
	cout << dp[n] << endl;
    
    return(0);
}
