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

vector<vector<int>> grafo;
vector<int> d;
int n, m;

int bfs(int origem, int destino, int trump)
{
    queue<int> q;
    q.push(origem);
    d = vector<int> (n, INF);
    d[origem] = 0;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        if (v == destino) return d[v];

        for (auto u : grafo[v])
        {
            if (u == trump) continue;
            if (d[u] > d[v] + 1)
            {
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    return(-1);
}

int main()
{
    while (cin >> n >> m)
    {
        grafo = vector<vector<int>>(n);
        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b; a--, b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        int c, r, e; cin >> c >> r >> e; c--, r--, e--;

        cout << bfs(c, r, e) << endl;
    }

    return(0);
}