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
	int n, m; cin >> n >> m;
	vector<int> v(n), dp(m+1, INF);
	dp[0] = 0;
	for (int& i : v) cin >> i;

	for (int i : v) {
		for (int j = i; j <= m; j++) {
			dp[j] = min(dp[j], dp[j-i] + 1);
		}
	}

	cout << dp[m] << endl;
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
