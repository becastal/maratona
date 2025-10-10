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
	setIO("clocktree");

	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> tam(2, 0), som(2, 0);
	function<void(int, int, int)> dfs = [&](int u, int p, int c) {
		tam[c]++, som[c] += a[u], som[c] %= 12;

		for (int v : g[u]) {
			if (v == p) continue;
			dfs(v, u, c ^ 1);
		}
	};
	dfs(0, -1, 0);

	int d = (som[0] - som[1] + 12) % 12;
	if (!d) return cout << n << endl, 0;
	if (d == 1) return cout << tam[0] << endl, 0;
	if (d == 11) return cout << tam[1] << endl, 0;
	cout << 0 << endl;

    return(0);
}
