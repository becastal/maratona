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

// dfs primeiro pra ver se todos predios estao conectados.
// se sim, seguir para kruskal somando arestas.

int n, m;
vector<int> id, sz;

int find(int x)
{
    return(id[x] = (id[x] == x ? x : find(id[x])));
}

void unir(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

int kruskal(vector<tuple<int, int, int>>& g)
{
    id = vector<int>(n + 1); iota(id.begin(), id.end(), 0);
    sz = vector<int>(n + 1, 1);
    int soma = 0;
    for (auto [w, u, v] : g)
    {
        if (find(u) != find(v))
        {
            unir(u, v);
            soma += w;
        }
    }
    return(soma);
}

bool conectado(vector<vector<int>>& g)
{
    vector<bool> visitado(g.size(), false);
    stack<int> s;
    s.push(0); visitado[0] = true;
    int verticesVisitados = 1;

    while (!s.empty())
    {
        int u = s.top(); s.pop();
        for (auto v : g[u])
        {
            if (visitado[v]) continue;
            s.push(v);
            visitado[v] = true;
            verticesVisitados++;
        }
    }
    return(g.size() == verticesVisitados);
}

int main()
{
    _;
    while (cin >> n >> m)
    {
        vector<vector<int>> grafo(n);
        vector<tuple<int, int, int>> arestas(m);
        for (int i = 0; i < m; i++)
        {
            int a, b, c; cin >> a >> b >> c; a--, b--;
            grafo[a].push_back(b), grafo[b].push_back(a);
            arestas.push_back({c, a, b});
        }

        if (!conectado(grafo)) cout << "impossivel" << endl;
        else
        {
            sz = vector<int>(grafo.size() + 1, 1);
            id = vector<int>(grafo.size() + 1);
            sort(arestas.begin(), arestas.end());
            cout << kruskal(arestas) << endl;
        }

    }

    return(0);
}