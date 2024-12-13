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

    int n, m, y; cin >> n >> m >> y;
    
    vector<vector<int>> M(n, vector<int>(m)), terra(n, vector<int>(m, 1));
    vector<queue<ii>> q((int)1e5 + 10);
    for (auto& l : M) for (auto& c : l) cin >> c;

    int res = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!i or !j or i == n - 1 or j == m - 1) {
                q[M[i][j]].emplace(i, j);
                terra[i][j] = 0;
            }
        }
    }

    vector<ii> movs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int yi = 1; yi <= y; yi++) {
        while (!q[yi].empty()) {
            res--;
            auto [ui, uj] = q[yi].front();
            q[yi].pop();

            for (ii mov : movs) {
                int vi = ui + mov.f, vj = uj + mov.s;
                if (vi < 0 or vj < 0 or vi == n or vj == m or !terra[vi][vj]) continue;

                q[max(yi, M[vi][vj])].emplace(vi, vj);
                terra[vi][vj] = 0;
            }
        }
        cout << res << endl;
    }

    return 0;
}
