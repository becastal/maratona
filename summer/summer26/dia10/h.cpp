#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, s; cin >> n >> s;
	vector<int> C(n), P(n), O(n);
	for (int& i : C) cin >> i;
	for (int& i : P) cin >> i;
	iota(all(O), 0);
	sort(all(O), [&](int i, int j) {
		return P[i] > P[j];
	});

	int k = 5;
	while (k < n and k * (k - 1) * (k - 2) / 6 <= s) k++;

	vector<int> dp(k + 1, LLONG_MAX);
	dp[0] = 0;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= 1; j--) if (dp[j-1] != LLONG_MAX) {
			dp[j] = min(dp[j], dp[j-1] + (C[O[i]] + P[O[i]] * (j - 1)));
			if (dp[j] <= s) {
				res = max(res, j);
			}
		}
	}
	cout << res << endl;

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

