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

// grafo com todos os vertices ligando a todos os computadores.
// kurskal pra achar mst.
int n;
vector<pair<int, int>> computadores;
vector<pair<double, pair<int, int>>> grafo;
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

double distanciaDoisPontos(pair<int, int>& p1, pair<int, int>& p2)
{
    return sqrt((p2.f - p1.f) * (p2.f - p1.f) + (p2.s - p1.s) * (p2.s - p1.s));
}

int main()
{
    _;
    while (~scanf("%d", &n))
    {
        computadores = vector<pair<int, int>>(n);
        for (int i = 0; i < n; i++) scanf("%d %d", &computadores[i].f, &computadores[i].s);

        grafo = vector<pair<double, pair<int, int>>>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                double w = distanciaDoisPontos(computadores[i], computadores[j]);
                grafo.push_back({ w, {i, j} });
            }

        sz = vector<int>(grafo.size(), 1);
        id = vector<int>(grafo.size());
        iota(id.begin(), id.end(), 0);
        sort(grafo.begin(), grafo.end());
        double cabos = 0;
        for (auto p : grafo)
        {
            if (find(p.s.f) != find(p.s.s))
            {
                unir(p.s.f, p.s.s);
                cabos += p.f;
            }
        }
        printf("%.2lf\n", cabos);
    }

    return(0);
}
