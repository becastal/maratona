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

int main()
{
    _;
	int n, m;
	function<bool(int, int)> valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;
	};

	// parece dp maneira. nao vi ainda dp de grid entao fica foda. n e m sao baixos ate.
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<int>> mp(n, vector<int> (m)), dp(n, vector<int> (m, 0));
		for (auto& l : mp)
			for (auto& c : l)
				cin >> c;

		if (n == m and n == 1) {
			cout << mp[0][0] << endl;
			continue;
		}

		int res = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (valido(i + 1, j))  {
					dp[i + 1][j] = max(dp[i + 1][j], __gcd(mp[i][j], mp[i + 1][j]));
					res = max(res, dp[i + 1][j]);
				}
				if (valido(i, j + 1)) {
					dp[i][j + 1] = max(dp[i][j + 1], __gcd(mp[i][j], mp[i][j + 1]));
					res = max(res, dp[i][j + 1]);
				}
			}

		cout << res << endl;	
	}
    
    return(0);
}
