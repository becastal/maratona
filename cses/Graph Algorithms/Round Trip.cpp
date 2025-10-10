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
 
	int n, m; cin >> n >> m;
 
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	int in, out;
	vector<int> cor(n, 0), pai(n, -1);
	function<int(int)> dfs = [&](int u) {
		cor[u] = 1;
		
		for (int v : g[u]) {
			if (v == pai[u]) continue;
			
			if (cor[v] == 0) {
				pai[v] = u;
				if (dfs(v)) return 1;
			} else if (cor[v] == 1) {
				in = v;
				out = u;
				return 1;
			}
		}
		
		cor[u] = 2;
		return 0;
	};
 
	int ok = 0;
	for (int i = 0; i < n and !ok; i++) {
		if (cor[i] == 0) {
			ok |= dfs(i);
		}
	}
 
	if (!ok) return cout << "IMPOSSIBLE" << endl, 0;
 
	vector<int> res = {in};
	for (int i = out; i != in; i = pai[i]) {
		res.push_back(i);
	}
	res.push_back(in);
	
	cout << res.size() << endl;
	for (int i : res) cout << i+1 << ' '; cout << endl;
    
    return(0);
}
