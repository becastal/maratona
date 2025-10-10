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

const int mod = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;

	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> dp(1 << 6, 0);
	for (int i = 0; i < n; i++) {
		vector<int> dp_(1 << 6, 0);
		for (int ii = 0; ii < (1 << 6); ii++) {
			dp_[ii] = (dp_[ii] + dp[ii]) % mod;
			dp_[ii & v[i]] = (dp_[ii & v[i]] + dp[ii]) % mod;
		}

		dp_[v[i]] = (dp_[v[i]] + 1) % mod;
		dp = move(dp_);
	}

	int res = 0;
	for (int i = 0; i < (1 << 6); i++) {
		if (__builtin_popcount(i) == k) {
			res = (res + dp[i]) % mod;
		}
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
