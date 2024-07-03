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
vector<vector<char>> a, b;
int n, m;

bool valido(ii p, vector<vector<char>>& g)
{
	return p.f >= 0 and p.s >= 0 and p.f < n and p.s < m and g[p.f][p.s] == '.';
}

vector<ii> bfs(vector<vector<char>>& g)
{
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<vector<ii>> pai(n, vector<ii>(m, {INF, INF}));
	queue<ii> q;
	q.push({0, 0});
	vis[0][0] = true;
	pai[0][0] = {-1, -1};

	while (!q.empty())
	{
		ii u = q.front(); q.pop();

		for (ii mov : movs)
		{
			ii v; v.f = u.f + mov.f, v.s = u.s + mov.s;
			if (valido(v, g) and !vis[v.f][v.s])
			{
				pai[v.f][v.s] = u;
				vis[v.f][v.s] = true;
				q.push(v);
			}
		}
	}

	ii ult = pai[n - 1][m - 1];
	vector<ii> res;
	while (ult.f != -1)
	{
		res.push_back(ult);
		ult = pai[ult.f][ult.s];
	}
	reverse(res.begin(), res.end());
	return res;
}

bool segue(vector<ii>& vii, vector<vector<char>>& g)
{
	for (auto p : vii)
		if (!valido(p, g))
			return false;

	return true;
}

int main()
{
    _;
	cin >> n >> m;

	a.resize(n, vector<char>(m));
	b.resize(n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];

	auto ca = bfs(a), cb = bfs(b);
	cout << (ca.size() == cb.size() and (segue(ca, b) or segue(cb, a))? "YES" : "NO") << endl;
    
    return(0);
}

