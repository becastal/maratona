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
typedef pair<int, int> ii;

vector<int> pai;
vector<map<int, int>> g;
int n, c;

vector<ii> dfs()
{
	vector<bool> vis(n, false);
	stack<int> s;
	vector<int> dist(n, INF);
	s.push(0); vis[0] = true; pai[0] = -1; dist[0] = 0;

	vector<ii> res;
	while (!s.empty())
	{
		int u = s.top(); s.pop();
		if (g[u].size() == 1 and g[u].begin()->f == pai[u])
			res.push_back({dist[u], u});

		for (auto [v, w] : g[u])
			if (!vis[v])
			{
				vis[v] = true;
				pai[v] = u;
				dist[v] = dist[u] + 1;
				s.push(v);
			}
	}
	return res;
}

int main()
{
    _;

	cin >> n >> c;
	vector<int> imp(n);
	for (auto& ei : imp)
		cin >> ei;

	g.resize(n);
	pai.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w; cin >> u >> v >> w; u--, v--;
		g[u].insert({v, w});
		g[v].insert({u, w});
	}

	vector<ii> folhas = dfs();
	priority_queue<ii> pq;
	for (auto f : folhas)
		pq.push(f);
	
	vector<bool> vis(n, false);
	int res = 0;
	while (!pq.empty())
	{
		int u = pq.top().s, d = pq.top().f; pq.pop();	
		if (vis[u]) continue;
		vis[u] = true;
		
		res += (imp[u] / c + !!(imp[u] % c)) * 2 * g[u][pai[u]];
		if (pai[u] != -1)
		{
			pq.push({d - 1, pai[u]});
			imp[pai[u]] += imp[u];
		}
		imp[u] = 0;
	}

	cout << res << endl;
    
    return(0);
}

