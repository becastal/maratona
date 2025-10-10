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

	int n; cin >> n;

	vector<string> V(n);
	for (auto& l : V) cin >> l;
	int m = (int)V[0].size();
	V.push_back(string(m, '-'));
	n++;

	vector<ii> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {2, 0}, {0, 2}, {-2, 0}, {0, -2}, {3, 0}, {0, 3}, {-3, 0}, {0, -3}, };
	auto valido = [&](ii a) {
		return a.f >= 0 and a.s >= 0 and a.f < n and a.s < m and V[a.f][a.s] != '.';
	};

	auto bfs = [&]() {
		queue<ii> q; q.emplace(0, 0);
		vector<vector<int>> d(n, vector<int>(m, INF));
		d[0][0] = 0;

		while (q.size()) {
			ii u = q.front(); q.pop();
			
			for (auto mov : movs) {
				ii v = {u.f + mov.f, u.s + mov.s};
				int w = abs(mov.f) > 1 or abs(mov.s) > 1;
				
				if (valido(v) and d[v.f][v.s] > d[u.f][u.s] + w) {
					d[v.f][v.s] = d[u.f][u.s] + w;
					q.emplace(v);
				}
			}
		}

		return d.back().back();
	};
	
	int res = bfs();
	cout << (res == INF ? "N" : to_string(res)) << endl;

    return(0);
}
