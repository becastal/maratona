#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int n, m;

void solve() {
    vector<vector<ll>> a(n, vector<ll>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] = (a[i][j] ? -100 : 1);
            if (j) a[i][j] += a[i][j - 1];
        }
    }

    ll res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            ll subRec = 0;
            for (int ii = 0; ii < n; ii++) {
                ll colSum = a[ii][j] - (i > 0 ? a[ii][i - 1] : 0);
                subRec = max(subRec + colSum, 0LL);
                res = max(res, subRec);
            }
        }
    }

    cout << res << endl;
}

int main() {
    _;
    while (cin >> n >> m && n && m) {
        solve();
    }
    return 0;
}

