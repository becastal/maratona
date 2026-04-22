#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, x; cin >> n >> x;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<array<int, 2>> dp((1 << n), {LLONG_MAX, 0});
	dp[0][0] = 1;

	for (int mask = 0; mask < (1 << n); mask++) {
		auto [cont, s] = dp[mask];

		for (int i = 0; i < n; i++) if (mask >> i & 1 ^ 1) {
			array<int, 2> agr;

			if (s + A[i] <= x) {
				agr = {cont, s + A[i]};
			} else {
				agr = {cont + 1, A[i]};
			}

			int mask_ = mask | (1 << i);
			dp[mask_] = min(dp[mask_], agr);
		}
	}
	cout << dp[(1 << n) - 1][0] << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

