#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;

int solve() {
    int x, y, z;
    if (!(cin >> x >> y >> z)) return 0;
    string S;
    cin >> S;
    int n = (int)S.size();

    vector<ll> dp(n + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> C(2, 0);
        C[S[i - 1] == 'A']++;
        for (int j = i - 1; j >= 0; j--) {
            if (j) C[S[j - 1] == 'A']++;

            if (dp[j] == LLONG_MAX) continue; // avoid overflow from INF

            ll c0 = C[0], c1 = C[1];
            ll cost1 = c0 * x + c1 * y;
            ll cost2 = c1 * x + c0 * y + 2LL * z;

            dp[i] = min(dp[i], dp[j] + min(cost1, cost2));
        }
    }

    cout << dp[n] << endl;
    return 0;
}

int main() {
    _;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

