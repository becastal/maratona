#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void setIO(string nome) {
    if (nome == "") return;
    freopen((nome + ".in").c_str(), "r", stdin);
    freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
    setIO("");

    int N, M, q; cin >> N >> M >> q;
    vector<string> mp(N);
    for (auto &s : mp) cin >> s;

    vector<vector<int>> a(N+1, vector<int>(M+1, 0)), h(N+1, vector<int>(M+1, 0)), v(N+1, vector<int>(M+1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i+1][j+1] = (mp[i][j] == '1');
            h[i+1][j+1] = (j + 1 < M and mp[i][j] == '1' and mp[i][j+1] == '1');
            v[i+1][j+1] = (i + 1 < N and mp[i][j] == '1' and mp[i+1][j] == '1');
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            h[i][j] += h[i-1][j] + h[i][j-1] - h[i-1][j-1];
            v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }

    auto query = [&](const vector<vector<int>>& pre, int x1, int y1, int x2, int y2) -> int {
        return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
    };
    
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int aa = query(a, x1, y1, x2, y2);
        int hh = query(h, x1, y1, x2, y2 - 1);
        int vv = query(v, x1, y1, x2 - 1, y2);

        cout << aa - hh - vv << endl;
    }
    
    return 0;
}

