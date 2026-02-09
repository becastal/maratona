#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

#define vi vector<int> 
vi vis;

void dfs(int v, vector<vi>& g, vi& output){
	vis[v] = 1;

	for(int u : g[v]){
		if(!vis[u])
			dfs(u, g, output);
	}
	output.push_back(v);
}

void scc(vector<vi>& g, vi& val){
	int n = g.size();
	vi order;

	vis.assign(n, 0);

	vector<vi> comps, g_cond;

	for(int i = 0; i < n; i++){
		if(!vis[i])
			dfs(i, g, order);
	}

	vector<vi> g_(n);

	for(int v = 0; v < n; v++)
		for(int u : g[v])
			g_[u].push_back(v);
	
	vis.assign(n, 0);
	reverse(order.begin(), order.end());

	vi roots(n, 0);
	vi sums(n, 0);

	for(auto v : order){
		if(!vis[v]){
			vi comp;
			dfs(v, g_, comp);
			comps.push_back(comp);

			int root = *min_element(all(comp));
			int sum = 0;
			for(auto u : comp) sum += val[u], roots[u] = root;
			sums[root] = sum;
		}
	}

	g_cond.assign(n, {});
	vi deg(n), dp(n);
	
	for(int v = 0; v < n; v++)
		for(auto u : g[v])
			if(roots[v] != roots[u]){
				g_cond[roots[v]].push_back(roots[u]);
				deg[roots[u]]++;
			}
	vi Vis(n);
	function<void(int)> dfs_ = [&] (int v){
Vis[v]=1;
		for(int u : g_cond[v]){
			deg[u]--;
			dp[u] = max(dp[u], dp[v] + sums[v]);
			if(deg[u] == 0){
				dfs_(u);
			}
		}
	};
	for(int i = 0; i < n; i++){
		if(deg[roots[i]] == 0 and !Vis[roots[i]]) dfs_(roots[i]);
	}

	int ans = 0;	
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[roots[i]] + sums[roots[i]]);
	}
	cout<<ans<<endl;
}
signed solve() {
	int n, m;cin>>n>>m;

	vector<int> val(n);
	for(int& x : val)cin>>x;

	vector<vi> g(n);

	for(int i = 0, x, y; i < m; i++){
		cin>>x>>y;x--, y--;

		g[x].push_back(y);
	}
	scc(g, val);
	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
