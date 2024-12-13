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

void solve() {
    int n; cin >> n; n++;
    vector dist(n, vector<int>(n, 0)), dp((1 << n), vector<int>(n, INF)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cin >> dist[i][j];
        }
    }

    dp[1][0] = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) <= 1) continue;

        if (!(mask & 1)) continue;

        for (int i = 0; i < n; i++) if (mask & (1 << i)) {
            for (int j = 0; j < n; j++) if (mask & (1 << j)) {
                dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i]);
            }
        }
    }

    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[(1 << n) - 1][i] + dist[i][0]);
    }
    cout << res << endl;
}

int main()
{
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

