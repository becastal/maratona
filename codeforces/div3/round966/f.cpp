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

int solve() {
    int n, k; 
    cin >> n >> k;
    vector<int> w(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
	// dp[i][j] = o minimo de operacoes pra chegar em j pontos tendo usado os primeiros i retangulos
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int x = w[i], y = h[i];
        int xy = x + y;
        int cost = 0;

        for (int j = 0; j <= xy; j++) {
            for (int ii = 0; ii + j <= k; ii++) {
                dp[i + 1][ii + j] = min(dp[i + 1][ii + j], dp[i][ii] + cost);
            }
            if (j < xy) {
                if (x >= y) {
                    x--; 
                    cost += y;
                } else {
                    y--; 
                    cost += x;
                }
            }
        }
    }

    cout << (dp[n][k] != INF ? dp[n][k] : -1) << endl;

    return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
