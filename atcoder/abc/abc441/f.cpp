#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

#define int ll

int solve() {
	int n, m; cin >> n >> m;
	string R(n, 'C');
	
	vector<int> P(n), V(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i] >> V[i];
	}

	vector<vector<int>> dpa(n+1, vector<int>(m+1, 0)), dpb(n+1, vector<int>(m+1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			dpa[i][j] = dpa[i-1][j];
			if (j >= P[i-1]) {
				dpa[i][j] = max(dpa[i][j], dpa[i-1][j - P[i-1]] + V[i-1]);
			}
		}
	}

	stack<array<int, 2>> St; St.push({n, m});
	vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0)); vis[n][m] = 1;

	while (St.size()) {
		auto [i, c] = St.top(); St.pop();
		if (!i) continue;;

		if (dpa[i][c] == dpa[i-1][c] and !vis[i-1][c]) {
			vis[i-1][c] = 1;
			St.push({i - 1, c});
		}

		if (c >= P[i-1] and dpa[i][c] == dpa[i-1][c - P[i-1]] + V[i-1]) {
			R[i - 1] = 'B';
			int c_ = c - P[i-1];
			if (!vis[i - 1][c_]) {
				vis[i - 1][c_] = 1;
				St.push({i-1, c_});
			}
		}
	}

	int S = *max_element(all(dpa[n]));

	reverse(all(P)), reverse(all(V));
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			dpb[i][j] = dpb[i-1][j];
			if (j >= P[i-1]) {
				dpb[i][j] = max(dpb[i][j], dpb[i-1][j - P[i-1]] + V[i-1]);
			}
		}
	}
	reverse(all(dpb));
	

	// pra definir quem eh A
	for (int i = 0; i < n; i++) {
		vector<int> mx = dpb[i + 1];

		for (int j = 1; j <= m; j++) {
			mx[j] = max(mx[j], mx[j-1]);
		}

		int s = 0;
		for (int j = 0, mxa = 0; j <= m; j++) {
			mxa = max(mxa, dpa[i][j]);
			s = max(s, mxa + mx[m - j]);	
		}

		if (s != S) {
			R[i] = 'A';
		}
	}

	cout << R << endl;

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

