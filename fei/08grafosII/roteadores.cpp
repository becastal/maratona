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

int r, c;
vector<pair<int, pair<int, int>>> grafo;
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

int main()
{
    _;
    cin >> r >> c;
    grafo = vector<pair<int, pair<int, int>>>();
    
    for (int i = 0; i < c; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        grafo.push_back({z, {x, y}});
        grafo.push_back({z, {y, x}});
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
    printf("%.0f\n", cabos);

    return(0);
}   
