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

const int maxn = 6000;
int main()
{
    _;

    vector<pair<int, int>> v;
    int w, s; 
    while (cin >> w >> s) {
        v.emplace_back(w, s);
    }

    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
        return a.s < b.s;
    });

    vector<int> dp(maxn + 1, INF);
    dp[0] = 0;

    int res = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = res; j >= 0; j--) {
            if (v[i].s >= dp[j] + v[i].f && dp[j] + v[i].f < dp[j + 1]) {
                dp[j + 1] = dp[j] + v[i].f;
                res = max(res, j + 1);
            }
        }
    }

    cout << res << endl;

    return(0);
}
