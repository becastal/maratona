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

map<ll, vector<ll>> g;
vector<ll> ve;
int n; 

int bfs()
{
	map<ll, int> dist, pai;
	for (ll vi : ve)
		dist[vi] = -1;
	dist[ve[0]] = 0;
	queue<ll> q;
	q.push(ve[0]);
	int ciclo = INF;
	
	while (!q.empty())
	{
		ll u = q.front(); q.pop();
		for (ll v : g[u])
			if (dist[v] >= dist[u])
				ciclo = min(ciclo, dist[u] + dist[v] + 1);
			else if (dist[v] == -1)
			{
				dist[v] = dist[u] + 1;			
				q.push(v);
			}
	}

	return (ciclo == INF ? -1 : ciclo);
}

int main()
{
    _;
	cin >> n;
	ve.resize(n);
	for (ll& vi : ve)
		cin >> vi;

	vector<int> bits(64, 0);
	for (ll vi : ve)
		for (int k = 0; k < 64; k++)
			if (vi & (1LL << k))
				bits[k]++;

	for (int bi : bits)
		if (bi >= 3)
		{
			cout << 3 << endl;
			return 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (ve[i] & ve[j])
			{
				g[ve[i]].push_back(ve[j]);
				g[ve[j]].push_back(ve[i]);
				// cout << ve[i] << ' ' << ve[j] << endl;
			}

	cout << bfs() << endl;
    
    return(0);
}
