#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l;
    string s;
    cin >> n >> k >> l >> s;

    // 1) build prefix sums
    vector<int> U(n+1,0), L(n+1,0);
    for(int i=0;i<n;i++){
        U[i+1] = U[i] + isupper(s[i]);
        L[i+1] = L[i] + islower(s[i]);
    }

    // 2) the segment-scheduling DP
    auto compute_best = [&](bool to_lower){
        const int NEG_INF = -1000000000;
        vector<int> dp_prev(n+1, NEG_INF), dp_curr(n+1, NEG_INF);
        dp_prev[0] = 0;
        for(int rep = 1; rep <= k; rep++){
            fill(dp_curr.begin(), dp_curr.end(), NEG_INF);
            // sweep through the string
            for(int i = 0; i < n; i++){
                // skip
                dp_curr[i+1] = max(dp_curr[i+1], dp_curr[i]);
                // take a length-l segment here?
                if(i + l <= n){
                    int gain = to_lower
                      ? (U[i+l] - U[i])
                      : (L[i+l] - L[i]);
                    dp_curr[i+l] = max(dp_curr[i+l], dp_prev[i] + gain);
                }
            }
            dp_prev.swap(dp_curr);
        }
        return dp_prev[n];
    };

    int best_tolower = compute_best(true);
    int best_toupper = compute_best(false);
    int delta0 = L[n] - U[n];

    // DEBUG OUTPUT
    cerr << "DEBUG: best_tolower = " << best_tolower
         << ", best_toupper = " << best_toupper
         << ", delta0 = " << delta0 << "\n";

    // 3) compute final answer
    int pos_delta  = delta0 + 2*best_tolower;
    int neg_delta  = delta0 - 2*best_toupper;
    int best_delta = max(abs(pos_delta), abs(neg_delta));
    int answer     = (n - best_delta) / 2;

    cout << answer << "\n";
    return 0;
}
