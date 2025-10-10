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
	vector<int> w(n), v(n);

	int tot = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i] >> w[i];
		tot += w[i];
	}

	vector<int> dp(tot+1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = tot; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}

	for (int i = 1; i <= tot; i++) {
		dp[i] = max(dp[i], dp[i-1]);
	}

	int res = 0;
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		res += dp[x];
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
