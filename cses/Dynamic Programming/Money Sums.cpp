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
 
    int n, k = 0; 
    cin >> n;
    vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i], k += v[i];
	}
 
	vector<vector<int>> dp(n + 1, vector<int> (k + 1)); 
	// dp[i][j]: 1 se da pra fazer valor j usando os i primeiros valores.
 
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			int ult = j - v[i - 1];
			if (ult >= 0 and dp[i - 1][ult]) {
				dp[i][j] = 1;
			}
		}
	}
    
	vector<int> res;
	for (int i = 1; i <= k; i++) {
		if (dp[n][i]) {
			res.push_back(i);
		}
	}
 
	cout << res.size() << endl;
	for (int i : res)
		cout << i << ' ';
	cout << endl;
 
    return 0;
}
