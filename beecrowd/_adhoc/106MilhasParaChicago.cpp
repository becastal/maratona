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

	int n, m;
	while (cin >> n and n) {
		cin >> m;

		vector<vector<pair<int, double>>> g(n);
		for (int i = 0, a, b, p; i < m; i++) {
			cin >> a >> b >> p; a--, b--;
			p /= 100;
			g[a].emplace_back(b, p);
			g[b].emplace_back(a, p);
		}

		vector<double> dist;

		auto dijkstra = [&] () {
			priority_queue<pair<double, int>> pq;
			dist[0] = 0;
		};

		dijkstra();
		cout << fixed << setprecision(6) << dist[n-1] << endl;
	}
    
    return(0);
}
