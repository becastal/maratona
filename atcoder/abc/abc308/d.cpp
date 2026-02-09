#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	string s = "snuke";

	vector<string> A(n);
	vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(5, 0)));
	
	for (auto& i : A) cin >> i;

	const vector<array<int, 2>> movs = {
		{-1, 0},
		{0, -1},
		{0, 1},
		{1, 0}
	};

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;
	};

	function<void(int, int, int)> dfs = [&](int ui, int uj, int k) {
		vis[ui][uj][k] = 1;

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj, k_ = (k + 1) % 5;
			if (valido(vi, vj) and !vis[vi][vj][k_] and A[vi][vj] == s[k_]) {
				dfs(vi, vj, k_);
			}
		}
	};
	if (s[0] == A[0][0]) dfs(0, 0, 0);

	int ok = 0;
	for (int i = 0; i < 5 and !ok; i++) {
		ok |= vis[n-1][m-1][i];	
	}
	cout << (ok ? "Yes" : "No") << endl;

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

