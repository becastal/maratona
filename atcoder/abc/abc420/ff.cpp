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
    int n, m, k; 
	cin >> n >> m >> k;

    vector<string> S(n+1);
    for (int i = 1; i <= n; ++i) cin >> S[i];

    // r[i][j] = # of consecutive '.' to the right starting at (i,j) inclusive
    vector<vector<int>> r(n+2, vector<int>(m+2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (S[i][j-1] == '*') r[i][j] = 0;
            else r[i][j] = r[i][j+1] + 1;
        }
    }

    vector<vector<int>> u(n+1, vector<int>(m+1, 0));
    vector<vector<int>> d(n+1, vector<int>(m+1, 0));
    vector<vector<ll>>  ans(n+3, vector<ll>(m+3, 0));

    // compute u (prev with STRICTLY greater) & d (next with GREATER-OR-EQUAL) per column
    for (int j = 1; j <= m; ++j) {
        stack<int> st;

        // u: pop while r[i][j] < r[st.top()][j]
        // => u[i][j] is 1 + last row above with r <= r[i][j]
        while (!st.empty()) st.pop();
        for (int i = 1; i <= n; ++i) {
            while (!st.empty() && r[i][j] < r[st.top()][j]) st.pop();
            u[i][j] = st.empty() ? 1 : (st.top() + 1);
            st.push(i);
        }

        // d: pop while r[i][j] <= r[st.top()][j]
        // => d[i][j] is -1 + first row below with r < r[i][j]
        while (!st.empty()) st.pop();
        for (int i = n; i >= 1; --i) {
            while (!st.empty() && r[i][j] <= r[st.top()][j]) st.pop();
            d[i][j] = st.empty() ? n : (st.top() - 1);
            st.push(i);
        }
    }

    // 4-point updates in the (height, width) diff arrays (one diff array per width)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int w = r[i][j];
            // safe even for w=0 due to padding; column 0 will never be read in output
            ans[1][w] += 1;
            ans[i - u[i][j] + 2][w] -= 1;
            ans[d[i][j] - i + 2][w] -= 1;
            ans[d[i][j] - u[i][j] + 3][w] += 1;
        }
    }

    // turn the height-diff into actual counts: two prefix passes over height, per width
    for (int w = 1; w <= m; ++w) {
        for (int h = 1; h <= n; ++h) ans[h][w] += ans[h-1][w];
        for (int h = 1; h <= n; ++h) ans[h][w] += ans[h-1][w];
    }

    // width accumulation: any i×w placement also counts for i×(w-1)
    for (int h = 1; h <= n; ++h) {
        for (int w = m; w >= 2; --w) ans[h][w-1] += ans[h][w];
    }

    // output n lines of m integers
	int res = 0;
    for (int h = 1; h <= n; ++h) {
        for (int w = 1; w <= m; ++w) {
            cout << ans[h][w] << (w == m ? '\n' : ' ');
			if (h * w < k) res += ans[h][w];
        }
    }
	cout << res << endl;

    return 0;
}

int main() { _
    int t = 1;
    while (t--) solve();
    return 0;
}
