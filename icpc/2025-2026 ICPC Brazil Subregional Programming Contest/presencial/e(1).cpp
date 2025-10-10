#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int n, m;cin>>n>>m;

	vector<vector<int>> g(n);	
	
	vector<vector<int>> res(n);

	for(int i = 0; i < m; i++){
		int x, y;cin>>x>>y;x--, y--;

		g[x].push_back(y);
	}
	
	vector<int> vis(n);
	int cont = 0;
	function<void(int)> dfs = [&](int source) {
		vis[source] = 1;

		for(int v : g[source]){
			if(!vis[v]){
				res[source].push_back(v);
				cont++;
				dfs(v);
			}
		}
	};

	for(int i = 0; i < n; i++) dfs(i);

	if(cont == m) return cout<<"*"<<endl, 0;

	for(int i = 0; i < n; i++){
		for(int x : res[i])
			cout<<i+1<<' '<<x+1<<endl;
	}
	return 0;
}
