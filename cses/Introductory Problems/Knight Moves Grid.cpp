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

int solve() {
	int n; cin >> n;
	
	vector<vector<int>> d(n, vector<int>(n, INF)); d[0][0] = 0;
	queue<pair<int, int>> q; q.emplace(0, 0);

	vector<pair<int, int>> movs = {
		{2, 1},
		{-2, 1},
		{2, -1},
		{-2, -1},
		{1, 2},
		{-1, 2},
		{1, -2},
		{-1, -2}
	};

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < n and d[i][j] == INF;
	};

	while (q.size()) {
		auto [ui, uj] = q.front(); q.pop();

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj)) continue;
			d[vi][vj] = d[ui][uj] + 1;
			q.emplace(vi, vj);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << " \n"[j==n-1];
		}
	}

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
