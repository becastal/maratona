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
	int n, m, R; cin >> n >> m >> R;

	vector<vector<pair<int, int>>> carro(n);
	int eu_pos, eu_dis, eu_tam;
	for (int i = 0, pos, tam, dis; i < m; i++) {
		cin >> pos >> tam >> dis;
		if (!i) {
			tie(eu_pos, eu_dis, eu_tam) = make_tuple(pos, dis, tam);	
		} else {
			carro[pos].emplace_back(dis, tam);	
		}
	}

	vector<vector<int>> g(n);
	vector<pair<int, int>> gap;

	int cont = 0, inicio = -1;
	for (int i = 0; i < n; i++) {
		carro[i].emplace_back(R, INF);
		sort(carro[i].begin(), carro[i].end());

		for (int j = 0, ult = 0; j < carro[i].size(); j++) {
			g[i].push_back(cont);
			gap.emplace_back(ult, carro[i][j].f);

			if (eu_pos == i and eu_dis >= ult) {
				inicio = cont;
			}

			ult = carro[i][j].f + carro[i][j].s;
			cont++;
		}
	}
	assert(inicio != -1);

	auto da = [&](double mi) {
		double preciso = eu_tam + 2 * mi;
		if (gap[inicio].second - gap[inicio].first < preciso) return 0;
		vector<vector<int>> adj(cont);
		for (int i = 0; i < n; i++) {
			for (int j : {i-1, i+1}) {
				if (j < 0 or j >= n) continue;

				for (int u : g[i]) {
					for (int v : g[j]) {
						int s = max(gap[u].f, gap[v].f);
						int e = min(gap[u].s, gap[v].s);

						if (e - s >= preciso) {
							adj[u].push_back(v);
							adj[v].push_back(u);
						}
					}
				}
			}
		}

		vector<int> vis(cont, 0);
		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			
			for (int v : adj[u]) {
				if (vis[v]) continue;
				dfs(v);
			}
		};
		dfs(inicio);

		for (int i : g[n-1]) {
			if (vis[i]) return 1;
		}
		return 0;
	};
	if (!da(0.0)) return cout << "Impossible" << endl, 0;

	double l = 0.0, r = R * 2.0;
	for (int t = 0; t < 1000; t++) {
		double mi = (l + r) / 2.0;

		if (da(mi)) {
			l = mi;
		} else {
			r = mi;
		}
	}

	cout << fixed << setprecision(12) << l << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
