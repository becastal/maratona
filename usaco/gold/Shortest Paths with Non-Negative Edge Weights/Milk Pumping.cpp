#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<int> F(m);
	vector<vector<array<int, 3>>> G(n);
	for (int i = 0, u, v, w, f; i < m; i++) {
		cin >> u >> v >> w >> f; u--, v--;
		G[u].push_back({v, w, f});
		G[v].push_back({u, w, f});
		F[i] = f;
	}
	sort(all(F));
	F.erase(unique(all(F)), F.end());

	array<int, 2> res{0, 1};

	for (int flow : F) {
		priority_queue<array<int, 2>> Pq; Pq.push({0, 0});
		vector<int> D(n, LLONG_MAX); D[0] = 0;

		while (Pq.size()) {
			auto [du, u] = Pq.top(); Pq.pop();
			if (-du != D[u]) continue;

			for (auto [v, w, f] : G[u]) if (f >= flow and D[v] > D[u] + w) {
				D[v] = D[u] + w;	
				Pq.push({-D[v], v});
			}
		}

		//cout << "flow: " << flow << ", D[n-1]: " << D[n-1] << endl;
		if (D[n-1] != LLONG_MAX) { 
			array<int, 2> agr{flow, D[n-1]};
			if (res[0] * agr[1] <  agr[0] * res[1]) {
				res = agr;
			}
		}
	}
	cout << res[0] * 1000000 / res[1] << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("pump");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
