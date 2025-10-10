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

const int maxn = 1001;

int main()
{
    _;

	vector<vector<ll>> dp(301, vector<ll>(maxn+1, 0));
	dp[0][0] = 1;

	//dp[i][j] de quantos jeitos da pra fazer i usando j moedas
	for (int i = 1; i <= 300; i++) {
		for (int j = i; j <= 300; j++) {
			for (int k = 1; k <= maxn; k++) {
				dp[j][k] += dp[j-i][k-1];
			}
		}
	}

	string s;
	while (getline(cin, s)) {
		vector<int> v;

		stringstream ss(s);
		int x;
		while (ss >> x) {
			v.push_back(x);
		}

		if (v.size() == 1) {
			int n = v[0];
			ll res = 0;
			for (int i = 0; i <= maxn; i++) {
				res += dp[n][i];	
			}
			cout << res << endl;
		} else if (v.size() == 2) {
			int n = v[0], l1 = v[1];

			ll res = 0;
			for (int i = 0; i <= l1; i++) {
				res += dp[n][i];	
			}
			cout << res << endl;
		} else if (v.size() == 3) {
			int n = v[0], l1 = v[1], l2 = v[2];

			ll res = 0;
			for (int i = l1; i <= l2; i++) {
				res += dp[n][i];
			}
			cout << res << endl;
		}
	}
    
    return(0);
}
