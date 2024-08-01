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

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        vector<int> dp(n + 2, -1);
        dp[0] = k;
        for (int i = 1; i <= n + 1; i++) {
            if (i != n + 1 and s[i - 1] == 'C') continue;

            for (int t = 1; t <= m; t++) {
                if (i - t >= 0 and (i - t == 0 or s[i - t - 1] == 'L')) {
                    dp[i] = max(dp[i], dp[i - t]);
                }
            }
            if (i > 1 and s[i - 2] == 'W') {
                dp[i] = max(dp[i], dp[i - 1] - 1);
            }
        }
        cout << (dp[n + 1] >= 0 ? "YES" : "NO") << endl;
    }
    
    return 0;
}

