#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
	}

	vector<int> Vis(n), Comp(n), Id(n);
	stack<int> S;

	int t = 0;
	function<int(int)> dfs = [&](int i){
		int lo = Id[i] = t++;
		S.push(i);
		Vis[i] = 2;

		for (int j : G[i]) {
			if (!Vis[j]) lo = min(lo, dfs(j));
			else if (Vis[j] == 2) lo = min(lo, Id[j]);
		}

		if (lo == Id[i]) while (1) {
			int u = S.top(); S.pop();
			Vis[u] = 1, Comp[u] = i;
			if (u == i) break;
		}
		
		return lo;
	};

	for (int i = 0; i < n; i++) if (!Vis[i]) {
		dfs(i);	
	}

	vector<int> CC(Comp);
	sort(all(CC));
	CC.erase(unique(all(CC)), CC.end());

	for (int& i : Comp) {
		i = lower_bound(all(CC), i) - CC.begin();
	}

	int nn = (int)CC.size();
	if (nn == 1) return cout << 0 << endl, 0;
	vector<int> In(nn), Out(nn);

	set<array<int, 2>> Ed;
	for (int u = 0; u < n; u++) {
		for (int v : G[u]) if (Comp[u] != Comp[v] and !Ed.count({Comp[u], Comp[v]})) {
			In[Comp[v]]++;
			Out[Comp[u]]++;
			Ed.insert({Comp[u], Comp[v]});
		}
	}

	int a = 0, b = 0;
	for (int u = 0; u < nn; u++) {
		if (!In[u]) a++;
		if (!Out[u]) b++;
	}
	cout << max(a, b) << endl;

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

