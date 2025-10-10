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

const int mod = 1e9+7;

int main()
{
    _;

	int n; cin >> n;
	vector<int> cor(n, -1), cont(2, 0), pot(n+1, 1);

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		pot[i] = (pot[i-1] << 1) % mod;
	}

	function<bool(int, int)> dfs = [&](int u, int c) {
		cor[u] = c;
		cont[cor[u]]++;
		for (int v : g[u]) {
			if (cor[v] == -1) {
				if (!dfs(v, !c)) {
					return 0;
				}
			}
			else if (cor[v] == c) return 0;
		}
		return 1;
	};
	dfs(0, 0);

	cout << cont[0] << ' ' << cont[1] << endl;
	cout << (pot[cont[0]] + pot[cont[1]]) % mod << endl;
    
    return(0);
}
