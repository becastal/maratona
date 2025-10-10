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
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		//g[v].emplace_back(u, w);
	}

	vector<ll> d(n, LINF); d[0] = 0;
	priority_queue<pair<ll, int>> pq; pq.emplace(0, 0);

	while (pq.size()) {
		auto [agr, u] = pq.top(); pq.pop();
		agr = -agr;

		if (d[u] < agr) continue;
		for (auto [v, w] : g[u]) {

			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;	
				pq.emplace(-d[v], v);
			}
		}
	}

	for (ll i : d) cout << i << ' '; cout << endl;
    
    return(0);
}
