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

vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<vector<int>> mp;
int n, m;

bool valido(ii p)
{
	return p.f >= 0 and p.s >= 0 and p.f < n and p.s < m and mp[p.f][p.s];
}

int bfs(ii p, ii fim)
{
	vector<vector<int>> d (n, vector<int>(m, INF));
	queue<ii> q;	
	q.push(p);
	d[p.f][p.s] = 1;

	while (!q.empty())
	{
		ii u = q.front(); q.pop();
		if (u == fim) return d[u.f][u.s];

		for (auto mov : movs)
		{
			ii v; v.f = u.f + mov.f, v.s = u.s + mov.s;
			if (valido(v) and d[v.f][v.s] == INF)
			{
				d[v.f][v.s] = d[u.f][u.s] + 1;
				q.push(v);
			}
		}
	}
	return INF;
}

int main()
{
    _;

	cin >> n >> m;
	mp.resize(n, vector<int>(m));

	ii p, fim;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 2)
				p.f = i, p.s = j;
			else if (mp[i][j] == 3)
				fim.f = i, fim.s = j;
		}

	cout << bfs(p, fim) << endl;
    
    return(0);
}
