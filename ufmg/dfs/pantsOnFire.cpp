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

map<string, set<string>> g;

bool dfs(string o, string d)
{
	map<string, bool> vis;
	stack<string> s;
	s.push(o);
	vis[o] = true;

	while (!s.empty())
	{
		string u = s.top(); s.pop();
		vis[u] = true;
		if (u == d) return true;

		for (auto v : g[u])
			if (!vis[v])
				s.push(v);
	}
	return false;
}

int main()
{
    _;

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string a, b, l;
		cin >> a >> l >> l >> l >> b;
		g[a].insert(b);
	}

	for (int i = 0; i < m; i++)
	{
		string a, b, l;
		cin >> a >> l >> l >> l >> b;
		
		if (dfs(a, b))
			cout << "Fact" << endl;
		else if (dfs(b, a))
			cout << "Alternative Fact" << endl;
		else
			cout << "Pants on Fire" << endl;
	}
    
    return(0);
}
