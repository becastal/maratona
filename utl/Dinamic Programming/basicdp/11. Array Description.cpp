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

int main() {
    _;

    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    // dp[i][j]: numero de jeitos de preencher a array ate i, se v[i] = j;
    if (v[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][v[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : {j - 1, j, j + 1}) {
                    if (k >= 1 && k <= m) {
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                    }
                }
            }
        } else {
            for (int k : {v[i] - 1, v[i], v[i] + 1}) {
                if (k >= 1 && k <= m) {
                    dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][k]) % mod;
                }
            }
        }
    }

    int res = 0;
    for (int j = 1; j <= m; j++) {
        res = (res + dp[n - 1][j]) % mod;
    }

    cout << res << endl;

    return 0;
}

