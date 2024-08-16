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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int s; cin >> s; s--;

    priority_queue<pair<int, int>> pq;
    vector<int> d(n, INF);
    d[s] = 0;
    pq.push({-0, s});
    
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        w = -w;
        if (w > d[u]) continue;

        for (auto [v, wv] : g[u]) {
            if (d[v] > d[u] + wv) {
                d[v] = d[u] + wv;
                pq.push({-d[v], v});
            }
        }
    }

    int dmin = INF, dmax = -INF;    
    for (int i = 0; i < n; i++) {
        if (i == s or d[i] == INF) continue;
        dmin = min(dmin, d[i]);
        dmax = max(dmax, d[i]);
    }

	cout << dmax - dmin << endl;	

    return 0;
}

