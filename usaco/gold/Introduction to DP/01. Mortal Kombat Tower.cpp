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
	int n; cin >> n;
	vector<int> v(n);
	vector<vector<int>> dp(n+1, vector<int>(2, INF));

	for (int& i : v) cin >> i;
	dp[0][1] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int ii = 1; ii <= min(n-i, 2); ii++) {
				int forte = v[i] + (ii > 1 ? v[i + 1] : 0);
				dp[i+ii][j^1] = min(dp[i+ii][j^1], dp[i][j] + j * forte);
			}
		}
	}

	cout << min(dp[n][0], dp[n][1]) << endl;
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
