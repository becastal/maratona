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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("factory");

	int n; cin >> n;
	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
	}

	vector<int> cont(n, 0);
	auto dfs = [&] (int in) {
		stack<int> s; vector<int> vis(n, 0);
		s.push(in), vis[in] = 1;

		while (s.size()) {
			int u = s.top(); s.pop();
			cont[u]++;

			for (int v : g[u]) {
				if (vis[v]) continue;
				s.push(v);
				vis[v] = 1;
			}
		}
	};

	for (int i = 0; i < n; i++) {
		dfs(i);
	}

	for (int i = 0; i < n; i++) {
		if (cont[i] == n) return cout << i+1 << endl, 0;		
	}

	cout << -1 << endl;
    return(0);
}
