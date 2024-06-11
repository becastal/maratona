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
	vector<bool> vis(n, false);

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int r = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			bool ciclo = true;
			stack<int> s;
			s.push(i);

			while (!s.empty())
			{
				int u = s.top(); s.pop();
				vis[u] = true;
				if (g[u].size() != 2) ciclo = false;
				for (auto v : g[u])
					if (!vis[v])
						s.push(v);
			}
			if (ciclo) r++;
		}
    
	cout << r << endl;

    return(0);
}
