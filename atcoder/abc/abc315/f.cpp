#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
	}

	auto euclides = [&](int a, int b) {
		return sqrtl((A[a][0] - A[b][0]) * (A[a][0] - A[b][0]) + (A[a][1] - A[b][1]) * (A[a][1] - A[b][1]));
	};

	const int k = 50;
	vector<vector<double>> dp(n, vector<double>(k + 1, 1e18));
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= max(0, i - k - 1); j--) {
			int s = i - j - 1;
			double d = euclides(i, j);
			for (int ii = 0; ii + s <= k; ii++) {
				if (dp[j][ii] == 1e18) continue;
				dp[i][ii + s] = min(dp[i][ii + s], dp[j][ii] + d);
			}
		}
	}

	double res = 1e18;
	for (int i = 0; i <= k; i++) {
		res = min(res, dp[n-1][i] + (i ? pow(2, i - 1) : 0.0));
	}
	cout << fixed << setprecision(13);
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

