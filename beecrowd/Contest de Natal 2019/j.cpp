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

	int n; 
	while (cin >> n and n) {
		vector<vector<int>> v(n, vector<int>(3));
		for (auto& l : v) for (auto& c : l) cin >> c;
		v.insert(v.begin(), {0, 0, 0});
		n++;

		vector<ii> movs = {{0, -1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}, {1, 2}, {1, -2}};
		auto valido = [&](ii a) {
			return a.f >= 0 and a.f < n and a.s >= 0 and a.s < 3 and !v[a.f][a.s];	
		};
		auto bfs = [&]() {
			queue<ii> q;
			vector<vector<int>> d(n, vector<int>(3, INF));
			q.emplace(0, 1);
			d[0][1] = 0;

			while (!q.empty()) {
				ii u = q.front(); q.pop();

				for (ii mov : movs) {
					ii v = {u.f + mov.f, u.s + mov.s};
					int di = abs(mov.s);

					if (valido(v) and d[u.f][u.s] + di < d[v.f][v.s]) {
						d[v.f][v.s] = d[u.f][u.s] + di;
						q.emplace(v);
					}
				}
			}

			int res = INF;
			for (int i = 0; i < 3; i++) {
				if (!v.back()[i]) res = min(res, d.back()[i]);
			}
			return res;
		};

		cout << bfs() << endl;
	}
    
    return(0);
}
