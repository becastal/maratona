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
 
const int mod = 1e9 + 7;
 
int main()
{
    _;
 
	int n; cin >> n;
	vector<vector<char>> mp(n, vector<char>(n));
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (auto& l : mp)
		for (auto& c : l)
			cin >> c;
	if (mp[0][0] == '*') return cout << 0 << endl, 0;
 
	auto valido = [&](int ii, int jj) {
		return ii >= 0 and jj >= 0 and ii < n and jj < n and mp[ii][jj] == '.';
	};
 
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (valido(i + 1, j)) dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % mod;
			if (valido(i, j + 1)) dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % mod;
		}
	}
 
	cout << dp[n-1][n-1] << endl;
    
    return(0);
}
