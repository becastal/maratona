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
typedef pair<int, int> ii;

void solve() {
	int N, M; cin >> N >> M;

	ii in;
	cin >> in.f >> in.s;

	int n; cin >> n; n++;
	vector<ii> p(n, in);
	vector<vector<int>> d(n, vector<int>(n, INF));

	for (int i = 1; i < n; i++) {
		cin >> p[i].f >> p[i].s;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = abs(p[i].f - p[j].f) + abs(p[i].s - p[j].s);
		}
	}

	vector<vector<int>> dp(1 << n, vector<int>(n+1, INF));
	dp[1][0] = 0;

	for (int i = 1; i < (1 << n); i++) {
		
		for (int u = 0; u < n; u++) {
			if (!(i & (1 << u))) continue;

			for (int v = 0; v < n; v++) {
				if (i & (1 << v)) continue;

				int ni = i | (1 << v);
				dp[ni][v] = min(dp[ni][v], dp[i][u] + d[u][v]);
			}
		}
	}

	int res = INF;
	for (int i = 0; i < n; i++) {
		res = min(res, dp[(1 << n)-1][i] + d[0][i]);
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
    
    return(0);
}
