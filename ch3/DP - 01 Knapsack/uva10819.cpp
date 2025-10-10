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

int W, n;
void solve() {
	vector<int> w(n), v(n);

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	int Wt = W;
	if (Wt > 1800) Wt += 200;

	vector<int> dp(Wt+1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = Wt; j >= w[i]; j--) {
			if (dp[j-w[i]] > 0 or j == w[i]) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}

	int res = 0;
	if (W >= 1801 and W <= 2000) {
		res = *max_element(dp.begin(), dp.begin() + W);
		for (int i = 2001; i <= Wt; i++) {
			res = max(res, dp[i]);
		}
	} else {
		res = *max_element(dp.begin(), dp.end());
	}

	cout << res << endl;
}

int main()
{
    _;

	while (cin >> W >> n) {
		solve();
	}
    
    return(0);
}
