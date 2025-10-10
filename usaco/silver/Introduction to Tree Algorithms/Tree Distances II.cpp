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
	setIO("");

	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<ll> d(n, 0), sub(n, 0), res(n, 0);
	function<ll(int, int)> dfs1 = [&](int u, int p) {
		res[0] += d[u];

		ll s = 0;
		for (int v : g[u]) {
			if (v == p) continue;
			d[v] = d[u] + 1;
			s += dfs1(v, u);
		}
		return sub[u] = 1 + s;
	};
	dfs1(0, -1);


	function<void(int, int)> dfs2 = [&](int u, int p) {
		for (int v : g[u]) {
			if (v == p) continue;
			res[v] = res[u] + n - 2 * sub[v];
			dfs2(v, u);
		}
	};
	dfs2(0, -1);

	for (ll i : res) cout << i << ' '; cout << endl;

    return(0);
}
