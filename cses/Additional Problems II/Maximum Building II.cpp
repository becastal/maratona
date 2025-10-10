#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;

int solve() {
    int n, m; 
    if (!(cin >> n >> m)) return 0;
    vector<string> A(n);
    for (auto &row : A) cin >> row;

    // Ha[i][j] = first row index >= i that is a '*' (or n if none)
    vector<vector<int>> Ha(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
        for (int l = 0, r; l < n; l = r) {
            r = l + 1;
            if (A[l][j] == '*') { Ha[l][j] = l; continue; }
            while (r < n && A[r][j] == '.') r++;
            for (int i = l; i < r; i++) Ha[i][j] = r;
        }
    }

    // We will build counts of subarrays whose minimum is EXACTLY h
    // via arithmetic-progression difference arrays per height.
    // For each height h in [1..n], we store two difference arrays over widths [1..m]:
    // val[w] = prefA[h][w] + (w-1) * prefB[h][w]
    vector<vector<ll>> A0(n + 2, vector<ll>(m + 3, 0)); // coefficient for constant term
    vector<vector<ll>> B0(n + 2, vector<ll>(m + 3, 0)); // coefficient for (w-1)

    auto add_AP = [&](int h, int L) {
        // add sequence over widths w=1..L: (L, L-1, ..., 1) to height bucket h
        if (h <= 0 || L <= 0) return;
        A0[h][1]        += L;
        A0[h][L + 1]    -= L;
        B0[h][1]        += -1;
        B0[h][L + 1]    -= -(-1); // i.e., +1
    };

    // Process each top row i: build histogram H[j] = max height downward from i
    vector<int> H(m), L(m), R(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) H[j] = max(0, Ha[i][j] - i);

        // Monotone stack to get previous strictly smaller and next strictly smaller
        stack<int> st;

        // L[j]: index of previous element with H < H[j] (or -1)
        while (!st.empty()) st.pop();
        for (int j = 0; j < m; j++) {
            while (!st.empty() && H[st.top()] >= H[j]) st.pop();
            L[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }

        // R[j]: index of next element with H < H[j] (or m)
        while (!st.empty()) st.pop();
        for (int j = m - 1; j >= 0; j--) {
            while (!st.empty() && H[st.top()] >= H[j]) st.pop();
            R[j] = st.empty() ? m : st.top();
            st.push(j);
        }

        // Each j is unique minimum on span len = R[j]-L[j]-1, with minimum value h=H[j]
        for (int j = 0; j < m; j++) {
            int h = H[j];
            if (h == 0) continue; // bars with 0 contribute nothing
            int len = R[j] - L[j] - 1;
            // Add triangle (len, len-1, ..., 1) to bucket for height h
            add_AP(h, len);
        }
    }

    // Build countsEqual[h][w] from difference arrays A0/B0
    vector<vector<ll>> equalCnt(n + 2, vector<ll>(m + 2, 0));
    for (int h = 1; h <= n; h++) {
        ll preA = 0, preB = 0;
        for (int w = 1; w <= m; w++) {
            preA += A0[h][w];
            preB += B0[h][w];
            equalCnt[h][w] = preA + (w - 1) * preB; // subarrays of width w with min == h
        }
    }

    // Turn "min == h" into "min >= h" via suffix over h
    // ans[h][w] = sum_{t >= h} equalCnt[t][w]
    for (int h = n - 1; h >= 1; h--) {
        for (int w = 1; w <= m; w++) {
            equalCnt[h][w] += equalCnt[h + 1][w];
        }
    }

    // Print n lines, each with m integers: number of placements for h x w
    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= m; w++) {
            cout << equalCnt[h][w] << " \n"[w == m];
        }
    }

    return 0;
}

int main() {
    _;
    int t = 1;
    while (t--) solve();
    return 0;
}
