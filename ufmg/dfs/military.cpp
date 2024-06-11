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
vector<int> ordem, inicio, tam;

void dfs(int u)
{
	inicio[u] = ordem.size();	
	ordem.push_back(u);
	for (int v : g[u])
		dfs(v);
	tam[u] = ordem.size() - inicio[u];
}

int main()
{
    _;
	int n, q; cin >> n >> q;
	g.resize(n);
	inicio.resize(n);
	tam.resize(n);

	for (int i = 1; i <= n - 1; i++)
	{
		int pi; cin >> pi; pi--;
		g[pi].push_back(i);
	}

	dfs(0);

	for (int i = 0; i < q; i++)
	{
		int u, k; cin >> u >> k; u--;
		cout << (k > tam[u] ? -1 : ordem[inicio[u] + k - 1] + 1) << endl;
	}

    return(0);
}
