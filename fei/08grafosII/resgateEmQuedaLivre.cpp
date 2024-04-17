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
vector<pair<double, pair<int, int>>> grafo;

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
    int C; cin >> C;
    while (C--)
    {
        cin >> n;
        herois = vector<pair<int, int>>(n);
        for (int i = 0; i < n; i++) cin >> herois[i].f >> herois[i].s;

        grafo = vector<pair<double, pair<int, int>>>();
        set<pair<int, int>> conexoes;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j || conexoes.count({j, i}) != 0) continue;
                double w = distanciaDoisPontos(herois[i], herois[j]);
                grafo.push_back({ w, {i, j} });
                conexoes.insert({i, j});
            }

        sz = vector<int>(grafo.size() + 1, 1);
        id = vector<int>(grafo.size() + 1);
        iota(id.begin(), id.end(), 0);
        sort(grafo.begin(), grafo.end());
        double teias = 0;
        for (auto p : grafo)
        {
            if (find(p.s.f) != find(p.s.s))
            {
                unir(p.s.f, p.s.s);
                teias += p.f;
            }
        }
        cout << fixed << setprecision(2) << teias/100 << endl;
    }

    return(0);
}