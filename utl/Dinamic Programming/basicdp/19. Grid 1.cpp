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

	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n, vector<char> (m));
	vector<vector<int>> dp(n, vector<int> (m, 0));
	for (auto& l : mp)
		for (auto& c : l)
			cin >> c;

	function<bool(pair<int, int>)> valido = [&] (pair<int, int> a) {
		return a.f >= 0 and a.s >= 0 and a.f < n and a.s < m and mp[a.f][a.s] == '.';
	};

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (pair<int, int> pos : {make_pair(i + 1, j), make_pair(i, j + 1)}) {
				if (!valido(pos)) continue;
				dp[pos.f][pos.s] = (dp[i][j] + dp[pos.f][pos.s]) % mod;
			}
		}
	}

	cout << dp[n - 1][m - 1] << endl;
    
    return(0);
}
