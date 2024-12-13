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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    _;
   	
	int n, m; cin >> n >> m;
	vector<vector<ii>> g(n);
	vector<int> temp(n);
	ordered_set temp_ord;
	for (int& i : temp) cin >> i, temp_ord.insert(i);
	int ni = temp_ord.size();

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	auto dijkstra = [&] (int in, int out, int menor, int maior) {
		vector<ll> d(n, INF);
		d[in] = 0;

		priority_queue<pair<ll, int>> pq;
		pq.emplace(0, in);

		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (u == out) return d[u];
			if (-ndist > d[u]) continue;

			for (auto [v, w] : g[u]) {
				if (d[v] > d[u] + w and (v == out or (temp[v] >= menor and temp[v] <= maior))) {
					d[v] = d[u] + w;
					pq.emplace(-d[v], v);
				}
			}
		}

		return (d[out] == INF ? -1 : d[out]);
	};

	int q; cin >> q;
	for (int i = 0, in, out, k, tipo; i < q; i++) {
		cin >> in >> out >> k >> tipo; in--, out--;

		int menor = -INF, maior = INF;
		if (tipo) {
			menor = *temp_ord.find_by_order(ni - k);
		} else {
			maior = *temp_ord.find_by_order(k - 1);	
		}
		cout << dijkstra(in, out, menor, maior) << endl;
	}

    return(0);
}
