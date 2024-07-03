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

vector<vector<int>> g(26);
vector<string> dic(26);
vector<bool> esta(26, 0), vis(26, 0), grav(26, 0);

bool dfs(int u, int pai)
{
	if (!vis[u])
	{
		grav[u] = vis[u] = true;	

		for (int v : g[u])
		{
			//printf("%c -> %c\n", u + 'a', v + 'a');
			if (v == pai) return true;

			if (!vis[v] and dfs(v, u))
				return true;
			else if (grav[v])
				return true;
		}
	}
	grav[u] = false;
	return false;
}

bool busca()
{
	for (int i = 0; i < 26; i++)
		if (esta[i] and dfs(i, -1))
			return true;
			
	return false;
}

int main()
{
    _;

	int n; cin >> n;
	bool ciclo = false;
	while (n--)
	{
		char li; cin >> li;
		string si; cin >> si;
		if (si.size() == 1 and si[0] == li) continue;
		dic[li - 'a'] = si;	
		
		for (char c : si)
			g[li - 'a'].push_back(c - 'a');
	}

	int ts; cin >> ts;
	string t; cin >> t;
	for (char c : t)
		esta[c - 'a'] = 1;

	if (not ciclo)
		ciclo = busca();

	if (ciclo)
	{
		cout << -1 << endl;
		return 0;
	}
	
	while (true)
	{
		string r = "";
		for (char c : t)
		{
			if (!dic[c - 'a'].empty())
				for (char ci : dic[c - 'a'])
					r.push_back(ci);
			else
				r.push_back(c);
		}

		if (t == r) break;
		t = r;
	}

	cout << t << endl;

	return 0;
}
