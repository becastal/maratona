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
	for (int i = 0; i < m; i++) {
		int x; cin >> x; x--;
		g[x].push_back(x+1);
		g[x+1].push_back(x);
	}

	vector<int> vis(n, 0);
	auto dfs = [&](int i) {
		vis[i] = 1;
		stack<int> s; s.push(i);
		set<int> S;
		S.insert(-i);

		while (s.size()) {
			int u = s.top(); s.pop();
			for (int v : g[u]) {
				if (!vis[v]) {
					vis[v] = 1;
					s.push(v);
					S.insert(-v);
				}
			}
		}

		return S;
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) for (int j : dfs(i)) {
			cout << (-j)+1 << ' ';
		}
	}
	cout << endl;
    
    return(0);
}
