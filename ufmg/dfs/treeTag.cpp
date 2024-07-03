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

vector<vector<int>> g;
int n, a, b, da, db;

vector<int> dfs(int a)
{
	stack<int> s; s.push(a);
	vector<int> d(g.size(), INF);
	d[a] = 0;

	while (!s.empty())
	{
		int u = s.top(); s.pop();
		for (int v : g[u])
			if (d[v] == INF)
			{
				d[v] = d[u] + 1;
				s.push(v);
			}
	}
	return d;
}

int distancia(int a, int b)
{
	auto d = dfs(a);
	return d[b];
}

int diametro()
{
	auto d = dfs(0);
	int maior = -INF, idx;
	for (int i = 0; i < n; i++)
		if (d[i] > maior)
		{
			maior = d[i];
			idx = i;
		}
	auto df = dfs(idx);
	int res = -INF;
	for (int i : df)
		res = max(res, i);
	return res;
}

string solve()
{
	cin >> n >> a >> b >> da >> db;
	a--, b--;

	g.clear();
	g.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (da >= distancia(a, b) or 2 * da >= diametro())
		return "Alice";
	else if (db > 2 * da)
		return "Bob";
	else
		return "Alice";
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
		cout << solve() << endl;
    
    return(0);
}
