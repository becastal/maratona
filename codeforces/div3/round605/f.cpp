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
typedef tuple<int, int, int> est;

int solve() {
	string s, t; cin >> s >> t;
	// dp[i][j][k]: tamanho da res tendo consumido i valores de s, j valores de t e tando com balanco b
	// 				nao tem porque guardar balanco negativo.
	// 				tenho que chegar em [n][m][0]. bfs nos estados.

	int n = (int)s.size(), m = (int)t.size();
	vector pai(n+1, vector<vector<est>>(m+1, vector<est>(n+m+1, est(-1, -1, -1))));
	vector vis(n+1, vector<vector<int>>(m+1, vector<int>(n+m+1, 0))), 
		   tipo(n+1, vector<vector<int>>(m+1, vector<int>(n+m+1, -1)));

	queue<est> q;
	q.emplace(0, 0, 0);
	vis[0][0][0] = 1;

	while (q.size()) {
		auto [i, j, k] = q.front(); q.pop();
		if (i == n and j == m and !k) break;

		for (char c : {'(', ')'}) {
			if ((c == ')' and !k) or (c == '(' and k == n+m)) continue;

			int i_ = i + (i < n and s[i] == c), j_ = j + (j < m and t[j] == c), k_ = k + (c == '(' ? +1 : -1);
			if (vis[i_][j_][k_]) continue;

			vis[i_][j_][k_] = 1;
			pai[i_][j_][k_] = est(i, j, k);
			tipo[i_][j_][k_] = (c == '(' ? +1 : -1);
			q.emplace(est(i_, j_, k_));
		}
	}
	assert(vis[n][m][0]);

	string res = "";
	for (auto [i, j, k] = est(n, m, 0); est(i, j, k) != est(0, 0, 0); tie(i, j, k) = pai[i][j][k]) {
		res.push_back(tipo[i][j][k] == +1 ? '(' : ')');
	}
	reverse(res.begin(), res.end());

	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
