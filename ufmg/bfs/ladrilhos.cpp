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
vector<vector<bool>> vis;
int h, l;

bool valido(ii p) {
    return p.f >= 0 and p.s >= 0 and p.f < h and p.s < l;
}

int bfs(ii p) {
    queue<ii> q;
    q.push(p);
    vis[p.f][p.s] = true;
    int tipo = mp[p.f][p.s];

    int c = 0;
    while (!q.empty())
	{
        ii u = q.front(); q.pop();
        c++;

        for (auto mov : movs)
		{
            ii v = {u.f + mov.f, u.s + mov.s};
            if (valido(v) and !vis[v.f][v.s] and mp[v.f][v.s] == tipo)
			{
                vis[v.f][v.s] = true;
                q.push(v);
            }
        }
    }
    return c;
}

int main() {
    _;

    cin >> h >> l;
    mp.resize(h, vector<int>(l));
    vis.assign(h, vector<bool>(l, false));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            cin >> mp[i][j];

    int menor = INF;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            if (!vis[i][j])
                menor = min(menor, bfs({i, j}));

    cout << menor << endl;

    return 0;
}

