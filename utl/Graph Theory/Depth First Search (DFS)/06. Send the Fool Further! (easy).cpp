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

    // caminho mais longo em uma arvore ponderada
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0, a, b, w; i < n - 1; i++) {
        cin >> a >> b >> w; 
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    auto dfs = [&](int src) {
        vector<int> d(n, -1); d[src] = 0;
        stack<int> s; s.push(src);
        pair<int, int> res = {0, 0};

        while (!s.empty()) {
            int u = s.top(); s.pop();
            for (auto [v, w] : g[u]) {
                if (d[v] != -1) continue;
                d[v] = d[u] + w;
                if (d[v] > res.s) {
                    res.s = d[v];
                    res.f = v;    
                }
                s.push(v);
            }
        }

        return res;
    };

    int res = dfs(0).s;
    
    cout << res << endl;

    return(0);
}