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

	int n;
	while (cin >> n and n) {
		n++;
		vector<pair<int, int>> v(n);
		for (auto& [x, y] : v) cin >> x >> y;

		vector<vector<double>> d(n, vector<double>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				d[i][j] = d[j][i] =
				sqrt((v[i].f - v[j].f) * (v[i].f - v[j].f) + (v[i].s - v[j].s) * (v[i].s - v[j].s));
			}
		}

		vector<vector<double>> dp(1 << n, vector<double>(n, 9e9));
		dp[1 << 0][0] = 0.0;
		
		for (int i = 0; i < (1 << n); i++) {
			for (int u = 0; u < n; u++) {
				if (!(i & (1 << u))) continue;

				for (int v = 0; v < n; v++) {
					if (i & (1 << v)) continue;
					
					int ni = i | (1 << v);
					dp[ni][v] = min(dp[ni][v], dp[i][u] + d[u][v]);
				}
			}
		}

		double res = 9e9;
		for (int i = 1; i < n; i++) {
			res = min(res, d[0][i] + dp[(1 << n)-1][i]);
		}
		cout << fixed << setprecision(2) << res << endl;
	}

    return(0);
}
