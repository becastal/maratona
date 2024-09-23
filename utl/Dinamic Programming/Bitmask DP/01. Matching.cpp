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

const int mod = 1e9 + 7;

int main()
{
    _;

	int n; cin >> n;
	vector<vector<int>> da(n, vector<int>(n));
	for (auto& l : da) for (auto& c : l) cin >> c;
	
	vector<int> dp(1 << n);
	dp[0] = 1;

	
	for (int mask = 0; mask < (1 << n) - 1; mask++) {
		int a = __builtin_popcount(mask);
		for (int b = 0; b < n; b++) {
			if (da[a][b] and !(mask & (1 << b))) {
				int mask2 = mask ^ (1 << b);
				dp[mask2] = (dp[mask2] + dp[mask]) % mod;
			}
		}
	}

	cout << dp[(1 << n) -1] << endl;
    
    return(0);
}
