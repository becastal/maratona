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
typedef pair<int, int> ii;

int main()
{
    _;

	int n, m, D; cin >> n >> m >> D;

	vector<ii> movs = {{1, 0},{0, 1},{-1, 0},{0, -1}};
	vector<vector<char>> M(n, vector<char>(m));
	vector<vector<int>> d(n, vector<int>(m, INF));
	queue<ii> q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'H') {
				q.emplace(i, j);
				d[i][j] = 0;
			}
		}
	}

	auto valido = [&](ii a) {
		return a.f >= 0 and a.s >= 0 and a.f < n and a.s < m and M[a.f][a.s] != '#' and d[a.f][a.s] == INF;
	};

	while (q.size()) {
		ii u = q.front(); q.pop();

		for (auto mi : movs) {
			ii v = ii(u.f + mi.f, u.s + mi.s);

			if (valido(v)) {
				q.emplace(v);	
				d[v.f][v.s] = d[u.f][u.s] + 1;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += d[i][j] <= D;
		}
	}
	cout << res << endl;

    return(0);
}
