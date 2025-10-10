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
	vector<int> v(n);
	for (int& i : v) cin >> i;
	vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

	for (int l = n-1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			dp[l][r] = max(v[l] - dp[l+1][r], v[r] - dp[l][r-1]);
		}
	}
	cout << dp[0][n-1] << endl;
    
    return(0);
}
