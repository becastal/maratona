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

int n, m; 
vector<vector<int>> g;
vector<int> d;

int dfs(int u)
{
	if (d[u] != -1) return d[u];

	int maior = 0;
	for (int v : g[u])
		maior = max(maior, dfs(v));

	return d[u] = maior + 1;
}

int main()
{
    _;

	cin >> n >> m;
	g.resize(n);
	d.assign(n, -1);

	while (m--)
	{
		int x, y; cin >> x >> y; x--, y--;
		g[x].push_back(y);
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, dfs(i));

	cout << res - 1 << endl;
    
    return(0);
}
