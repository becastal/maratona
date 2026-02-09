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

	string res = "", S;
	for (int t = 0; t < n; t++) {
		cin >> S;
		int m = (int)S.size();

		if (t) {
			vector<int> P(m);
			for (int i = 1, j = 0; i < m; i++) {
				while (j and S[j] != S[i]) j = P[j-1];
				P[i] = (j += S[i] == S[j]);
			}

			int j = 0;
			for (int i = max(0LL, (int)res.size() - 2 * m); i < (int)res.size(); i++) {
				while (j and res[i] != S[j]) j = P[j-1];
				j += (res[i] == S[j]);
			}
			res += S.substr(j);
			
		} else res = S;
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

