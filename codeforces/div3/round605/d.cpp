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
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<int> dp(n, 1), dp_(n, 1);
	for (int i = n-2; i >= 0; i--) {
		if (a[i] < a[i+1]) dp[i] = dp[i+1] + 1;	
	}

	for (int i = 1; i < n; i++) {
		if (a[i-1] < a[i]) dp_[i] = dp_[i-1] + 1;
	}

	//for (int i : dp) cout << i << ' '; cout << endl;
	//for (int i : dp_) cout << i << ' '; cout << endl;

	int res = max(*max_element(dp.begin(), dp.end()), *max_element(dp_.begin(), dp_.end()));
	for (int i = 1; i < n - 1; i++) {
		if (a[i-1] < a[i+1]) {
			res = max(res, dp_[i-1] + dp[i+1]);
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
