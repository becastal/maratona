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
	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n, vector<char>(m));
	vector<vector<bool>> vis(n, vector<bool>(m));

	ll num = 0, den = m * n;
	for (auto& l : mp) {
		for (auto& c : l) {
			cin >> c;
		}
	}

	auto valido = [&](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m and !vis[i][j] and mp[i][j] == '#';
	};
	
	vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	auto dfs = [&](int si, int sj) -> ll {
		stack<pair<int, int>> s;
		s.emplace(si, sj);
		vis[si][sj] = 1;

		ll tam = 0;
		while (!s.empty()) {
			auto [ui, uj] = s.top(); s.pop();
			tam++;

			for (auto mov : movs) {
				int vi = ui + mov.f, vj = uj + mov.s;
				if (valido(vi, vj)) {
					vis[vi][vj] = 1;
					s.emplace(vi, vj);
				}
			}
		}
		return tam;
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == '#' and !vis[i][j]) {
				ll ki = dfs(i, j);
				num += ki * ki;
			}
		}
	}

	ll comum = __gcd(num, den);
	if (den == comum) return cout << num / comum << endl, 0;
	cout << num / comum << " / " << den / comum << endl;

	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
