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

void solve(int n) {
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	vector<vector<int>> dp(n, vector<int>(2, 1));

	int res = 0;
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].f == v[j].f) continue;

			if (v[j].s == v[i].s + 2) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			if (v[j].s == v[i].s - 2) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}
		res = max({res, dp[i][0], dp[i][1]});
	}

	cout << res << endl;
}

int main()
{
    _;

	int n;
	while (cin >> n) {
		solve(n);
	}
    
    return(0);
}
