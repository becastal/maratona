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

	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n, vector<char>(m));
	vector<vector<int>> d(n, vector<int>(m, -1));

	vector<pair<int, int>> robos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '@') {
				robos.emplace_back(i, j);
			}
		}
	}

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;
	};

   	vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; 
	for (auto [a, b] : robos) {
		d[a][b] = 0;
		for (auto [dx, dy] : movs) {
			int i = 1;
			while (valido(a + dx * i, b + dy * i)) {
				int na = a + dx * i, nb = b + dy * i;
				if (d[na][nb] == -1) d[na][nb] = i;
				d[na][nb] = min(d[na][nb], i);
				i++;
				if (mp[na][nb] == '@') break;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[i][j] == -1) return cout << -1 << endl, 0;
			res = max(res, d[i][j]);
		}
	}

	cout << res << endl;	

    return(0);
}
