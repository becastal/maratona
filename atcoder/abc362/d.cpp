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
	vector<vector<pair<int, int>>> g(n);
	vector<int> peso(n);
	for (int& i : peso) cin >> i;

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w + peso[v]);
		g[v].emplace_back(u, w + peso[u]);
	}

	vector<ll> d(n, LINF);
	auto dijkstra = [&]() {
		d[0] = peso[0];
		priority_queue<pair<ll, int>> pq;
		pq.emplace(d[0], 0);
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[u]) continue;

			for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
				d[idx] = d[u] + w;
				pq.emplace(-d[idx], idx);
			}
		}
	};
	dijkstra();

	for (int i = 1; i < n; i++) {
		cout << d[i] << " \n"[i==n-1];
	}

    return(0);
}
