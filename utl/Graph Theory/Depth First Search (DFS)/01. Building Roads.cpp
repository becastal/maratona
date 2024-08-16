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

    int n, m; 
    cin >> n >> m;
    vector<vector<int>> g(n);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; 
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n, 0), pai;
    function<void(int)> dfs = [&](int u) -> void {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            pai.push_back(i);
            dfs(i);
        }
    }

    cout << pai.size() - 1 << endl;
    for (int i = 0; i < (int)pai.size() - 1; i++) {
        cout << pai[i] + 1 << ' ' << pai[i + 1] + 1 << endl;
    }
    
    return 0;
}

