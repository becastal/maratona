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
	for (int i = 1, pi; i <= n-1; i++) {
		cin >> pi; pi--;
		g[i].push_back(pi);
		g[pi].push_back(i);
	}

	vector<int> likes(n), lis(n, 1), vis(n, 0); 
	for (int& i : likes) cin >> i;

	vector<int> vi;
	function<void(int)> dfs = [&] (int u) {
		vis[u] = 1;

		auto it = lower_bound(vi.begin(), vi.end(), likes[u]);
		int novo, antigo, pos;
		if (novo = it == vi.end()) {
			vi.push_back(likes[u]);
		} else {
			antigo = *it;
			pos = it - vi.begin();
			*it = likes[u];
		}
		lis[u] = (int) vi.size();
		
		for (int v : g[u]) {
			if (vis[v]) continue;
			dfs(v);
		}

		if (novo) {
			vi.pop_back();
		} else {
			vi[pos] = antigo;
		}
	};
	dfs(0);

	for (int i = 1; i < n; i++) cout << lis[i] << ' '; cout << endl;
    
    return(0);
}
