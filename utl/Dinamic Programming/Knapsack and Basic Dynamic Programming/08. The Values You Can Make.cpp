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
    vector<int> v(n);
    for (int& i : v) cin >> i;

	// uma variacao de money sums. 
	// dp[i][j][k] eh 1 se tem um subset com as i primeiras que tenha soma j e que senha um subset com soma k.
	// dp[i][j][k] = dp[i-1][j][k] | dp[i-1][j-vi][k] | dp[i-1][j-vi][k-vi];
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(k+1, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int ii = 0; ii <= k; ii++) {
                dp[i][j][ii] |= dp[i-1][j][ii];
                if (j >= v[i-1]) {
					dp[i][j][ii] |= dp[i-1][j-v[i-1]][ii];
					if (ii >= v[i-1]) dp[i][j][ii] |= dp[i-1][j][ii-v[i-1]];
				}
            }
        }
    }

    vector<int> res;
    for (int i = 0; i <= k; i++) {
        if (dp[n][k][i]) res.push_back(i);
    }

    cout << (int)res.size() << endl;
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " \n"[i==(int)res.size()-1];
    }
    
    return 0;
}

