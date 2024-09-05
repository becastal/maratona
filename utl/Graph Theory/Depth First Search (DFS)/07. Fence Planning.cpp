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

int main()
{
    _;

    int n, m; cin >> n >> m;
    vector<pair<int, int>> vaca(n);
    for (auto& [x, y] : vaca) cin >> x >> y;

    vector<vector<int>> g(n);
    for (int i = 0, a, b; i < m ; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(n, 0);
    auto dfs = [&](int src) {
        stack<int> s; s.push(src); vis[src] = 1;
        int minx = vaca[src].f, maxx = vaca[src].f; 
        int miny = vaca[src].s, maxy = vaca[src].s; 

        while (!s.empty()) {
            int u = s.top(); s.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    s.push(v);

                    minx = min(minx, vaca[v].f), maxx = max(maxx, vaca[v].f);
                    miny = min(minx, vaca[v].s), maxy = max(maxy, vaca[v].s);
                }
            }
        }

        return 2 * (maxy - miny) + 2 * (maxx - minx);
    };

    int res = INF;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            res = min(res, dfs(i));
        }
    }

    cout << res << endl;
    
    return(0);
}