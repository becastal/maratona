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

void solve() {
    int n, m, h; cin >> n >> m >> h;
    // dijkstra diferenciado pra cada, dai itero nas dists e res = min(max(xi, yi))

    vector<int> cavalo(n, 0);
    for (int i = 0; i < h; i++) {
        int x; cin >> x; x--;
        cavalo[x] = 1;
    }

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    auto dijkstra = [&](int in) {
        vector<array<ll, 2>> d(n, {LINF, LINF});
        //d[in][0] = d[in][1] = 0;
        d[in][cavalo[in]] = 0;

        priority_queue<tuple<ll, int, int>> pq;
        pq.emplace(0, in, cavalo[in]);

        while (pq.size()) {
            auto [ndist, u, com_cavalo] = pq.top(); pq.pop();
            ndist = -ndist;
            if (ndist > d[u][com_cavalo]) continue;

            for (auto [idx, w] : g[u]) {
                int cavaloi = com_cavalo | cavalo[idx];
                int wi = (com_cavalo ? w / 2 : w);
                
                if (d[idx][cavaloi] > d[u][com_cavalo] + wi) {
                    d[idx][cavaloi] = d[u][com_cavalo] + wi;
                    pq.emplace(-d[idx][cavaloi], idx, cavaloi);
                }
            }
        }

        return d;
    };

    auto R = dijkstra(0), M = dijkstra(n-1);
    ll res = LINF;
    for (int i = 0; i < n; i++) {
        if (R[i][0] == LINF and R[i][1] == LINF or M[i][0] == LINF and M[i][1] == LINF) continue;

        ll ri = min(R[i][0], R[i][1]);
        ll mi = min(M[i][0], M[i][1]);
        res = min(res, max(ri, mi));
    }

    cout << (res == LINF ? -1 : res) << endl;
}

int main() {
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

