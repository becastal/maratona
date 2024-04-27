#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<ll> id, sz;
vector<bool> visitado;
vector<vector<int>> grafo;

int find(int x)
{
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unir(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

struct aresta {
    ll u;
    ll v;
    ll w;
    bool operator<(const aresta& other) const {
        return w < other.w;
    }
};

void dfs(int v)
{
    visitado[v] = true;
    for (auto u : grafo[v])
        if (!visitado[u]) dfs(u);
}

int main()
{
    _;
    ll n; cin >> n;
    vector<aresta> arestas;
    for (ll a = 0; a < n - 1; a++)
    {
        ll k; cin >> k;
        for (ll b = 0; b < k; b++)
        {
            aresta novaAresta;
            novaAresta.u = a;
            cin >> novaAresta.v >> novaAresta.w; novaAresta.v--;
            arestas.push_back(novaAresta);
        }
    }

    ll tamanho = 0;

    id = vector<ll>(n); iota(id.begin(), id.end(), 0);
    sz = vector<ll>(n, 1);
    grafo = vector<vector<int>>(n);
    sort(arestas.begin(), arestas.end());
    for (auto a : arestas)
    {
        if (find(a.u) != find(a.v))
        {
            unir(a.u, a.v);
            tamanho += a.w;
            grafo[a.u].push_back(a.v); grafo[a.v].push_back(a.u);
        }
    }

    ll componentes = 0;
    
    visitado = vector<bool>(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visitado[i])
        {
            dfs(i);
            componentes++;
        }
    }

    cout << componentes << " " << tamanho << endl;
    return(0);
}