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
typedef pair<int, int> ii;

int main()
{
    _;

    int n, m; cin >> n >> m;
    vector<vector<ii>> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; u--, v--;
        g[u].emplace_back(v, w);
    }

    auto dijkstra = [&] () {
        vector<array<ll, 2>> d(n, {LINF, LINF});
        d[0][0] = d[0][1] = 0;

        priority_queue<tuple<ll, int, int>> pq;
        pq.emplace(0, 0, 0); // dist, vert, usou

        while (!pq.empty()) {
            auto [ndist, u, usou] = pq.top(); pq.pop();
            ndist = -ndist;

            if (ndist > d[u][usou]) continue;

            for (auto [v, w] : g[u]) {
                if (d[v][0] > d[u][usou] + w) {
                    d[v][0] = d[u][usou] + w;
                    pq.emplace(-d[v][0], v, 0);
                }

                if (!usou and d[v][1] > d[u][0] + w / 2) {
                    d[v][1] = d[u][0] + w / 2;
                    pq.emplace(-d[v][1], v, 1);
                }

                if (usou and d[v][1] > d[u][1] + w) {
                    d[v][1] = d[u][1] + w;
                    pq.emplace(-d[v][1], v, 1);
                }
            }
        }

        return min(d[n-1][0], d[n-1][1]);
    };

    cout << dijkstra() << endl;

    return 0;
}

