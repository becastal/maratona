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
vector<int> dist;

void dfs(int v)
{
	for (auto w : g[v])
		if (dist[w] == INF)
		{
			dist[w] = dist[v] + 1;
			dfs(w);
		}
}

int main()
{
    _;

	int n; cin >> n;
	g = vector<vector<int>> (n);
	dist = vector<int> (n, INF);
	for (int i = 0; i < n - 1; i ++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dist[0] = 0;
	dfs(0);

	int pos, maior = -INF;
	for (int i = 0; i < n; i++)
		if (dist[i] > maior)
		{
			maior = dist[i];
			pos = i;
		}

	fill(dist.begin(), dist.end(), INF);
	dist[pos] = 0;
	dfs(pos);

	int dim = -INF;
	for (auto d : dist)
		dim = max(dim, d);

	cout << dim << endl;
    
    return(0);
}
