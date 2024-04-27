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
vector<pair<int, int>> herois;

struct aresta 
{
    int u;
    int v;
    double w;
    bool operator<(const aresta& other) const {
        return w < other.w;
    }
};

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

double distanciaDoisPontos(pair<int, int>& a, pair<int, int>& b)
{
    return sqrt((b.f - a.f) * (b.f - a.f) + (b.s - a.s) * (b.s - a.s));
}

double kruskal(vector<aresta>& g)
{
    id = vector<int>(n + 1); iota(id.begin(), id.end(), 0);
    sz = vector<int>(n + 1, 1);
    double soma = 0;
    for (auto a : g)
    {
        if (find(a.u) != find(a.v))
        {
            unir(a.u, a.v);
            soma += a.w;
        }
    }
    return(soma);
}

int main()
{
    _;
    int C; cin >> C;
    while (C--)
    {
        cin >> n;
        herois = vector<pair<int, int>>(n);
        for (int i = 0; i < n; i++) 
            cin >> herois[i].f >> herois[i].s;

        vector<aresta> arestas;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                aresta novaAresta;
                novaAresta.w = distanciaDoisPontos(herois[i], herois[j]);
                novaAresta.u = i, novaAresta.v = j;
                arestas.push_back(novaAresta);
            }
        }

        sort(arestas.begin(), arestas.end());
        double teias = kruskal(arestas);
        cout << fixed << setprecision(2) << teias / 100 << endl;
    }

    return(0);
}