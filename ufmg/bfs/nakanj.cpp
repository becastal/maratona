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

vector<ii> movs = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} };

bool valido(ii p)
{
	return p.f >= 0 and p.s >= 0 and p.f < 8 and p.s < 8;
}

int bfs(ii a, ii b)
{
	vector<vector<int>> d (8, vector<int>(8, INF));
	queue<ii> q;
	q.push(a);
	d[a.f][a.s] = 0;

	while (!q.empty())
	{
		ii u = q.front(); q.pop();
		if (u == b) return d[u.f][u.s];

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

	int t; cin >> t;
	while (t--)
	{
		ii a, b;	
		char a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;

		a.f = a1 - 'a', a.s = a2 - '1';
		b.f = b1 - 'a', b.s = b2 - '1';

		cout << bfs(a, b) << endl;
	}
    
    return(0);
}
