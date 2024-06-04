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

int n, m;
vector<vector<int>> d;

bool floyd_warshall (vector<vector<int>>& d) {
    for (int k = 0; k < n ; k++)
        for (int i = 0; i < n ; i++)
            for (int j = 0; j < n ; j++)
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
    
    for (int i = 0; i < n ; i ++)
        if (d[i][i] < 0) return true;

    return false;
}

int main()
{
    _;
    int instancias = 0;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int i = 0; i < m; i++)
        {
            int u, v, w; cin >> u >> v >> w; u--, v--;
            dist[u][v] = w;
            dist[v][u] = w;
        }

        bool ciclosNegativos = floyd_warshall(dist);

        cout << "Instancia " << ++instancias << endl;
        int q; cin >> q;
        while (q--)
        {
            int u, v; cin >> u >> v; u--, v--;
            cout << (u == v ? 0 : dist[u][v]) << endl;
        }
        cout << endl;
    }

    return(0);
}
