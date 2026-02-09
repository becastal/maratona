#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

aaaaaaaaaa

aaaaaaaaa
a * 10: 3
aa * 5: 3

*/

const int MAX = 8010;
int C[MAX][MAX], P[MAX][MAX];

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	auto tam = [](int a) {
		int res = 0;	
		while (a) {
			res++;				
			a /= 10;
		}
		return res;
	};

	for (int l = 0; l < n; l++) {
		for (int i = 1 + l, j = 0; i < n; i++) {
			while (j and S[i] != S[l + j]) j = P[l][l + j - 1];
			P[l][i] = (j += S[i] == S[l + j]);
		}

		for (int r = l; r < n; r++) {
			int m = r - l + 1;
			C[l][r] = m + 1;

			int t = m - P[l][r];
			if (m % t == 0) {
				C[l][r] = t + tam(m / t);
			}
		}
	}

	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) if (dp[j] != LLONG_MAX) {
			dp[i] = min(dp[i], dp[j] + C[j][i-1]);
		}
	}
	cout << dp[n] << endl;

//	vector<vector<int>> dp(n, vector<int>(n, -1));
//	function<int(int, int)> calc = [&](int l, int r) {
//		auto& res = dp[l][r];
//		if (res != -1) return dp[l][r];	
//		//printf("(%lld, %lld)\n", l, r);
//
//		res = C[l][r];
//		for (int m = l; m < r; m++) {
//			res = min(res, calc(l, m) + calc(m + 1, r));
//		}
//		return res;
//	};
//	cout << calc(0, n-1) << endl;

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

