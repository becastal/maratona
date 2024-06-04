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

int n, m, s;

void floyd_warshall(vector<vector<int>>& d)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
}

int main()
{
    _;

	while (cin >> n >> m >> s)
	{
		vector<vector<int>> dist(n, vector<int>(n, 0));

		for(int i = 0; i < n; i++)
			dist[i][i] = 0;

		for (int i = 0; i < m; i++)
		{
			int a, b, w; cin >> a >> b >> w; a--, b--;
			dist[a][b] = w;
			dist[b][a] = w;
		}

		floyd_warshall(dist);
		while (s--)
		{
			int u, v; cin >> u >> v; u--, v--;
			cout << dist[u][v] << endl;
		}
	}
    
    return(0);
}
