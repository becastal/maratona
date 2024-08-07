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
	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < 15 and j < 15;
	};
	vector<pair<int, int>> movs = {{-2, 1},{-2, -1},{1, -2},{-1, -2}};
	vector<vector<int>> dp(15, vector<int> (15, 0));
    dp[0][0] = false; dp[0][1] = false; dp[0][2] = true; dp[1][0] = false; dp[1][1] = false; dp[2][0] = true;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			for (auto [dx, dy] : movs) {
				if (valido(i + dx, j + dy) and !dp[i + dx][j + dy]) {
					dp[i][j] = 1;
				}
			}
		}
	}

	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y; x--, y--;
		cout << (dp[x][y] ? "First" : "Second") << endl;
	}
    
    return(0);
}
