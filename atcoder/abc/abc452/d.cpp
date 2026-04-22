#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S, T; cin >> S >> T;
	int n = (int)S.size(), m = (int)T.size();

	vector<vector<int>> Prox(n + 1, vector<int>(26, n));
	for (int i = n-1; i >= 0; i--) {
		Prox[i] = Prox[i + 1];
		Prox[i][S[i] - 'a'] = i;
	}

	int res = n * (n + 1) / 2;
	for (int l = 0; l < n; l++) {
		int r = l, ok = 1;

		for (char c : T) {
			if (r > n) {
				ok = 0;
				break;
			}

			int r_ = Prox[r][c - 'a'];
			if (r_ == n) {
				ok = 0;
				break;
			}

			r = r_ + 1;
		}

		if (ok) {
			res -= (n - (r - 1));
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

