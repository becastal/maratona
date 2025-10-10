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

	vector<int> ceos;
	for (int i = 0, p; i < n; i++) {
		cin >> p; 
		if (!p) {
			ceos.push_back(i);
			continue;
		}

		p--;
		g[i].push_back(p);
		g[p].push_back(i);
	}
    
	vector<int> cont(n, 0);
	function<int(int, int)> dfs = [&](int u, int p) {
		cont[u] = 1;	
		for (int v : g[u]) {
			if (v == p) continue;	
			cont[u] += dfs(v, u);
		}
		return cont[u];
	};

	int res, contr = -1;
	for (int i : ceos) {
		dfs(i, -1);
		if (cont[i] > contr) {
			res = i;
			contr = cont[i];
		}
	}

	cout << res+1 << ' ' << contr << endl;	

    return(0);
}
