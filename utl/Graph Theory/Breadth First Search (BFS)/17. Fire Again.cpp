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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<ii> q;

    int k; cin >> k;
    for (int i = 0, ui, uj; i < k; i++) {
        cin >> ui >> uj; ui--, uj--;
        q.emplace(ui, uj);
        d[ui][uj] = 1;
    }

    vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    auto valido = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m and d[i][j] == -1;
    };

    auto bfs = [&]() {
        while (!q.empty()) {
            auto [ui, uj] = q.front(); q.pop();

            for (auto mov : movs) {
                int vi = ui + mov.f, vj = uj + mov.s;
                if (!valido(vi, vj)) continue;

                q.emplace(vi, vj);
                d[vi][vj] = d[ui][uj] + 1;
            }
        }
    };
    bfs();
    
    int longe = 0; ii onde;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] <= longe) continue;

            longe = d[i][j];
            onde = ii(i+1, j+1);
        }
    }

    cout << onde.f << ' ' << onde.s << endl;
    
    return 0;
}

