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

int solve(int n, int m) {
	vector<vector<pair<int, double>>> g(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		double w; cin >> w; w /= 100.0;
		w = -log(w);
		g[u].emplace_back(v, w);	
		g[v].emplace_back(u, w);	
	}

	auto dij = [&]() {
		vector<double> d(n, LINF); d[0] = 0;
		priority_queue<pair<double, int>> pq; pq.emplace(0, 0);
	 
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[u]) continue;
	 
			for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
				d[idx] = d[u] + w;
				pq.emplace(-d[idx], idx);
			}
		}
		return exp(-d[n-1]);
	};

	cout << fixed << setprecision(6);
	cout << dij() * 100.0 << " percent" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (cin >> t and t) {
		int t_; cin >> t_;
		solve(t, t_);
	}
    
    return(0);
}
