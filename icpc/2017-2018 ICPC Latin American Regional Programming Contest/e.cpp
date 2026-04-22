#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;
	int n, m = (int)S.size(); cin >> n;


	vector<int> Pot(m + 1, 1);
	for (int i = 1; i <= m; i++) {
		Pot[i] = Pot[i-1] * 10 % n;
	}

	vector<vector<array<int, 3>>> Pai(m+1, vector<array<int, 3>>(n, {-1, -1, -1}));
	vector<vector<int>> Vis(m+1, vector<int>(n));

	function<void(int, int)> dfs = [&](int i, int s) {
		Vis[i][s] = 1;
		if (i == m) return;

		int l = (S[i] == '?' ? (i == 0 ? 1 : 0) : S[i] - '0'), 
			r = (S[i] == '?' ? 9 : S[i] - '0');
		
		for (int c = l; c <= r; c++) {
			int s_ = (s + c * Pot[m - i - 1] % n) % n;

			if (!Vis[i+1][s_]) {
				Pai[i+1][s_] = {i, s, c};
				dfs(i+1, s_);
			}
		}
	};
	dfs(0, 0);

	if (!Vis[m][0]) return cout << "*" << endl, 0;

	string T = "";
	for (int i = m, s = 0; i; ) {
		auto [i_, s_, c] = Pai[i][s];
		T.push_back(char('0' + c));
		i = i_, s = s_;
	}
	reverse(all(T));
	cout << T << endl;

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

