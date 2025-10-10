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

void solve() {
	int n, p; cin >> n >> p;
	vector<ii> P, X;
	vector<vector<char>> M(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'G') P.emplace_back(i, j);
			if (M[i][j] == 'X') X.emplace_back(i, j);
		}
	}

	vector<vector<vector<int>>> d(p, vector<vector<int>>(n, vector<int>(n, INF)));
	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	auto valido = [&](ii a) {
		return a.f >= 0 and a.s >= 0 and a.f < n and a.s < n and M[a.f][a.s] != '#';
	};

	auto bfs = [&](int in) {
		queue<ii> q; q.emplace(P[in]);
		d[in][P[in].f][P[in].s] = 0;

		while (q.size()) {
			ii u = q.front(); q.pop();

			for (ii mov : movs) {
				ii v = {u.f + mov.f, u.s + mov.s};
				if (valido(v) and d[in][v.f][v.s] == INF) {
					d[in][v.f][v.s] = d[in][u.f][u.s] + 1;
					q.emplace(v);
				}
			}
		}
	};

	for (int i = 0; i < p; i++) {
		bfs(i);
	}

	int res = INF;
	do {
		int agr = -INF;
		for (int i = 0; i < p; i++) {
			agr = max(agr, d[i][X[i].f][X[i].s]);
		}
		res = min(res, agr);
	} while(next_permutation(X.begin(), X.end()));

	cout << (res == INF ? -1 : res) << endl;
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
