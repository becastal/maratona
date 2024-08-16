#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
typedef pair<int, int> ii;

int main()
{
    _;

    int n, m, l; cin >> n >> m;
    vector<vector<ii>> mp(n, vector<ii>(m));    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            bool b = (c == 'M');
            mp[i][j] = {b, !b};
        }
    }
    cin >> l;

    vector<vector<ii>> pref(n + 1, vector<ii>(m + 1, {0, 0}));    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j].f = mp[i - 1][j - 1].f + pref[i - 1][j].f + pref[i][j - 1].f - pref[i - 1][j - 1].f;
            pref[i][j].s = mp[i - 1][j - 1].s + pref[i - 1][j].s + pref[i][j - 1].s - pref[i - 1][j - 1].s;
        }
    }

    int res = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - l + 1 > 0 and j - l + 1 > 0) {
                ii soma;
                int x1, x2, y1, y2;
                y2 = i, y1 = i - l + 1, x2 = j, x1 = j - l + 1;
                soma.f = pref[y2][x2].f 
                         - (y1 > 1 ? pref[y1 - 1][x2].f : 0) 
                         - (x1 > 1 ? pref[y2][x1 - 1].f : 0) 
                         + (y1 > 1 && x1 > 1 ? pref[y1 - 1][x1 - 1].f : 0);
                soma.s = pref[y2][x2].s 
                         - (y1 > 1 ? pref[y1 - 1][x2].s : 0) 
                         - (x1 > 1 ? pref[y2][x1 - 1].s : 0) 
                         + (y1 > 1 && x1 > 1 ? pref[y1 - 1][x1 - 1].s : 0);
                if (soma.f and soma.s) res = max(res, soma.f * 12 + soma.s * 25);
            }
        }
    }
    cout << res << endl;

    return 0;
}

