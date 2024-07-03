#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    // dp array to store the maximum profit for each amount of dough used
    vector<int> dp(n + 1, 0);

    // First consider buns without stuffing
    for (int i = c0; i <= n; ++i) {
        dp[i] = max(dp[i], dp[i - c0] + d0);
    }

    // Now consider each type of bun with stuffing
    for (int j = 0; j < m; ++j) {
        int ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;

        // We need to consider making up to (ai / bi) buns with this stuffing type
        int max_buns = ai / bi;

        // We use a reverse loop to prevent over-counting in the same iteration
        for (int k = 0; k < max_buns; ++k) {
            for (int i = n; i >= ci; --i) {
                dp[i] = max(dp[i], dp[i - ci] + di);
            }
        }
    }

    // The answer is the maximum value in the dp array
    int max_profit = *max_element(dp.begin(), dp.end());
    cout << max_profit << endl;

    return 0;
}

