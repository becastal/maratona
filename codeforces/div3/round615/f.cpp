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

	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> pai(n, -1);
	function<pair<int, int>(int)> dfs = [&] (int in) {
		fill(pai.begin(), pai.end(), -1);
		vector<int> d(n, INF); d[in] = 0;
		stack<int> s; s.emplace(in);

		int res = in, dmax = 0;
		while (s.size()) {
			int u = s.top(); s.pop();	

			if (d[u] > dmax) {
				dmax = d[u];
				res = u;
			}

			for (int v : g[u]) {
				if (d[v] != INF) continue;

				d[v] = d[u] + 1;
				pai[v] = u;
				s.emplace(v);
			}
		}

		return make_pair(dmax, res);
	};

	int a = -1;
	auto [res, b] = dfs(a = dfs(0).s);
	vector<int> diam;
	for (int i = b; i != -1; i = pai[i]) {
		diam.push_back(i);
	}

	if (diam.size() == n) {
		return cout << n-1 << endl << diam[0]+1 << ' ' << diam[1]+1 << ' ' << diam.back()+1 << endl, 0;
	}

	function<pair<int, int>(vector<int>)> bfs = [&](vector<int> P) {
		vector<int> d(n, INF);
		queue<int> s;
		for (int i : P) {
			s.emplace(i);
			d[i] = 0;
		}

		int res, dmax = -1;
		while (s.size()) {
			int u = s.front(); s.pop();	

			if (d[u] > dmax) {
				dmax = d[u];
				res = u;
			}

			for (int v : g[u]) {
				if (d[v] != INF) continue;

				d[v] = d[u] + 1;
				s.emplace(v);
			}
		}

		return make_pair(dmax, res);
	};
	
	auto [res_, c] = bfs(diam);
	cout << res_ + res << endl << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
   	 
    return(0);
}
