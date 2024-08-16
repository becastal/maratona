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

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> vert(n, {0, INF});
	for (auto& [i, j] : vert) cin >> i;

	vector<int> d(n, INF), pai(n);
	vector<vector<int>> g(n);
	for (int u = 1, v; u <= n - 1; u++) {
		cin >> v; v--;
		pai[u] = v;
		g[u].push_back(v);
		g[v].push_back(u);
		cout << u << ' ' << v << endl;
	}

	d[0] = 0;
	priority_queue<pair<int, int>> pq;
	function<void(int)> dfs = [&] (int u) {
		pq.push({d[u], u});	
		for (int v : g[u]) {
			if (d[v] == INF) {
				d[v] = d[u] + 1;
				dfs(v);
			}
		}
	};
	dfs(0);

	while (!pq.empty()) {
		auto [w, u] = pq.top(); pq.pop();
		int val = vert[u].f;
		val += (vert[u].s != INF ? vert[u].s : 0); 
		//cout << w << ' ' << u << ' ' << val << endl;
		vert[pai[u]].s = min(vert[pai[u]].s, val); 
	}

	auto r = vert[0];
	cout << r.f + (r.s != INF ? r.s : 0) << endl;
}

int main()
{
    _;

	// comeco das folhas e vou subindo. quando acho um pai, somo nele o valor do menor filho. 
	// faco isso ate chegar na raiz, ou dist zero. talvez mais facil com pq.

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
