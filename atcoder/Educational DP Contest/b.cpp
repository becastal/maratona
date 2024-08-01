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
	
	int n, k; cin >> n >> k;
	vector<int> v(n), dp(n, INF);
	for (int& i : v) cin >> i;

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i + j >= n) continue;
			dp[i + j] = min(dp[i + j], dp[i] + abs(v[i] - v[i + j]));
		}
	}

	cout << dp[n - 1] << endl;
    
    return(0);
}
