#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<string> A(2);
	cin >> A[0] >> A[1];
	
	vector<int> Dp((1 << 2), LLONG_MAX);
	Dp[0] = 0;

	for (int i = 0; i < n; i++) {
		vector<int> Dp_((1 << 2), LLONG_MAX);
		
		// nada
		if (Dp[0] != LLONG_MAX) {
			// 10
			// 10
			Dp_[0] = min(Dp_[0], (Dp[0] + (A[0][i] != A[1][i])));

			// 11 horiz
			// 11
			if (i + 1 < n) {
				Dp_[3] = min(Dp_[3], Dp[0] + (A[0][i] != A[0][i + 1]) + (A[1][i] != A[1][i + 1]));
			}
		}

		// de cima
		if (Dp[1] != LLONG_MAX and i + 1 < n) {
			Dp_[2] = min(Dp_[2], Dp[1] + (A[1][i] != A[1][i + 1]));
		}

		if (Dp[2] != LLONG_MAX and i + 1 < n) {
			Dp_[1] = min(Dp_[1], Dp[2] + (A[0][i] != A[0][i + 1]));
		}

		if (Dp[3] != LLONG_MAX) {
			Dp_[0] = min(Dp_[0], Dp[3]);
		}

		Dp = move(Dp_);
	}

	cout << *min_element(all(Dp)) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

