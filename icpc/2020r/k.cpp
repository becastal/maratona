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

int p, f;
vector<vector<int>> g;
vector<bool> vis;

int bfs(int v)
{
	queue<int> q; q.push(0);

	int res = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		res++;
		for (int v : g[u])
			if (!vis[v])
			{
				vis[v] = true;
				q.push(v);
			}
	}

	return res;
}

int main()
{
    _;

	cin >> p >> f;	
	g.resize(p);

	while (f--)
	{
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vis.assign(p, 0);
	vector<int> comp;
	for (int i = 0; i < p; i++)
		if (!vis[i])
			comp.push_back(bfs(i));

	cout << comp.size() << endl;
	cout << p << endl;
	if (comp.size() == 1 and (p % 2 == 1 or p == 1))
		cout << 'N' << endl;
	else
		cout << 'Y' << endl;

    return(0);
}
