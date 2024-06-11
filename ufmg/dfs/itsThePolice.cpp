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
	vector<bool> vis(n);
	vector<int> res(n, 1);

	for (int i = 0; i < m; i++)
	{
		int aj, bj; cin >> aj >> bj; aj--, bj--;
		g[aj].push_back(bj);
		g[bj].push_back(aj);
	}

	// pegar componente com a menor quantidade de blocos, e dentro dele configurar da melhor maneira possivel.

	vector<int> menorc(n + 1);
	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			stack<int> s; s.push(i);
			vector<int> comp;

			while (!s.empty())
			{
				int u = s.top(); s.pop();
				vis[u] = true;
				comp.push_back(u);
				for (auto v : g[u])
					if (!vis[v])
						s.push(v);
			}
			if (comp.size() <= menorc.size())
				menorc = comp;
		}

	// agora, no menor componente, escolher o vertice que tem menor peso escolher ele como o lugar em que podem ficar os bandidos.

	int menorv = m + 1, pos;
	for (auto v : menorc)
		if (menorv < g[v].size())
		{
			menorv = g[v].size();
			pos = v;
		}

	res[pos] = 0;	
	for (auto v : g[pos])
		res[v] = 0;

	for (auto v : res)
		cout << v << ' ';
	cout << endl;
    
    return(0);
}
