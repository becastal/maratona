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

    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    map<pair<int, int>, int> s;
    for (int i = 0, a, b, w; i < n; i++) {
        cin >> a >> b >> w; a--, b--;
        g[a].push_back({b, 0});
        g[b].push_back({a, w});
        s[{a, b}] = 0;
        s[{b, a}] = w;
    }
    
    vector<int> vis(n, 0), cam;
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        cam.push_back(u);
        for (auto [v, w] : g[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };

    dfs(0); 
    int a = 0, b = 0;
    for (int i = 0; i < n - 1; i++) {
        a += s[{cam[i], cam[i + 1]}];
        b += s[{cam[i + 1], cam[i]}];
    }
    a += s[{cam[n - 1], cam[0]}], b += s[{cam[0], cam[n - 1]}];

    cout << min(a, b) << endl;

    return 0;
}
