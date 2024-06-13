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

vector<vector<char>> mp;
int n, m;

bool valido(ii p)
{
	return p.f >= 0 and p.s >= 0 and p.f < n and p.s < m;
}

void bfs(ii p)
{
	vector<vector<bool>> vis(n, vector<bool>(m));
	queue<ii> q;
	q.push(p);
	vis[p.f][p.s] = true;

	while (!q.empty())
	{
		ii u = q.front(); q.pop();
		mp[u.f][u.s] = 'o';
		
		ii dir = {u.f, u.s + 1}, esq = {u.f, u.s - 1}, bx = {u.f + 1, u.s};
		if (!valido(bx))
			continue;

		if (mp[bx.f][bx.s] == '.' and !vis[bx.f][bx.s])
		{
			q.push(bx);
			vis[bx.f][bx.s] = true;
		}
		else if (mp[bx.f][bx.s] == '#')
		{
			if (!vis[dir.f][dir.s]) q.push(dir), vis[dir.f][dir.s] = true;
			if (!vis[esq.f][esq.s]) q.push(esq), vis[esq.f][esq.s] = true;
		}
	}
}

int main()
{
    _;
	cin >> n >> m;
	mp.resize(n, vector<char>(m));

	ii p;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 'o')
				p.f = i, p.s = j;
		}
		
	bfs(p);

	for (auto l : mp)
	{
		for (auto c : l)
			cout << c;
		cout << endl;
	}
    
    return(0);
}
