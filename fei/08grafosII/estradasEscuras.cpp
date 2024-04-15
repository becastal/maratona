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
    while (true)
    {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;

        id = vector<int> (n);
        sz = vector<int> (n, 1);
        iota(id.begin(), id.end(), 0);

        vector<tuple<int, int, int>> grafo; // {peso, v1, v2}
        int custo = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, w; cin >> a >> b >> w;
            custo += w;
            grafo.emplace_back(w, a, b);
        }

        sort(grafo.begin(), grafo.end());
        for (auto [w, a, b] : grafo)
        {
            if (find(a) != find(b))
            {
                unir(a, b);
                custo -= w;
            }
        }
        cout << custo << endl;
    }

    return(0);
}