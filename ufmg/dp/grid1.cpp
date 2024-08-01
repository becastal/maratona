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

	int h, w; cin >> h >> w;
	vector<vector<char>> mp(h, vector<char>(w));
	vector<vector<int>> dp(h, vector<int>(w));
	for (auto& l : mp)
		for (auto& c : l)
			cin >> c;

	function<bool(int, int)> valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < h and j < w and mp[i][j] != '#';
	};

	dp[0][0] = 1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			if (valido(i - 1, j)) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			if (valido(i, j - 1)) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
		}

	cout << dp[h - 1][w - 1] << endl;
    
    return(0);
}
