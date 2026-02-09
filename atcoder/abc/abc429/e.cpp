#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const int INF = 1e6;

/*
bfs multisource, mas tenho que manter duas distancias pra cada vertice
-> e mais: tenho que manter quem foi o primeiro, pra nao repetir.
*/

int solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    string S; cin >> S;

    // D[u][k] = {dist, origem}
    vector<vector<array<int, 2>>> D(n, vector<array<int, 2>>(2, {INF, -1}));

    // mantém D[v][0] como a melhor (menor dist) e D[v][1] como a segunda
    auto ordena = [&](int v) {
        if (D[v][1][0] < D[v][0][0]) swap(D[v][0], D[v][1]);
    };

    queue<array<int, 3>> Q; // {dist, u, origem}
    for (int u = 0; u < n; u++) if (S[u] == 'S') {
        Q.push({0, u, u});
        D[u][0] = {0, u};
    }

    while (!Q.empty()) {
        auto [Du, u, ini] = Q.front(); Q.pop();

        for (int v : G[u]) {
            for (int k : {0, 1}) if (Du + 1 < D[v][k][0] and ini != D[v][k][1]) {
                D[v][k] = {Du + 1, ini};
                Q.push({Du + 1, v, ini});
                ordena(v);
                break;
            }
        }
    }

    for (int u = 0; u < n; u++) if (S[u] == 'D') {
        cout << D[u][0][0] + D[u][1][0] << endl;
    }

    return 0;
}

int main() {
    _;
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}

