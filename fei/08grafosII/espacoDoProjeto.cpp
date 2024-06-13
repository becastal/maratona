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

int n;
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

int main()
{
    cin >> n;
    vector<tuple<int, int, int>> arestas;
    for (int i = 0; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        arestas.push_back({w, u, v});
    }

    sort(arestas.begin(), arestas.end());
    int minimo = kruskal(arestas);

    reverse(arestas.begin(), arestas.end());
    int maximo = kruskal(arestas);

    cout << maximo << endl << minimo << endl;
    return(0);
}
