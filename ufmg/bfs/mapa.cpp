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
vector<vector<char>> mp;
int l, c;

bool valido(ii p)
{
	return p.f >= 0 and p.s >= 0 and p.f < l and p.s < c and mp[p.f][p.s] == 'H';
}

ii bfs(ii p)
{
	vector<vector<bool>> vis (l, vector<bool>(c, false));
	queue<ii> q;
	q.push(p);
	vis[p.f][p.s] = true;

	ii u;
	while (!q.empty())
	{
		u = q.front(); q.pop();
		
		for (auto mov : movs)
		{
			ii v; v.f = u.f + mov.f, v.s = u.s + mov.s;
			if (valido(v) and !vis[v.f][v.s])
			{
				q.push(v);
				vis[v.f][v.s] = true;
			}
		}
	}
	return u;
}

int main()
{
    _;

	cin >> l >> c;
	mp.resize(l, vector<char>(c));
	ii p;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 'o') 
				p.f = i, p.s = j;
		}
	
	ii fim = bfs(p);
	cout << fim.f + 1 << ' ' << fim.s + 1 << endl;
    
    return(0);
}
