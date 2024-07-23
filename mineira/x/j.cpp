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
// tinha notado que era uma variacao do knapsack, mas sofri pra implementar.
const int MAXK = 100 + 10;
const int MAXN = 500 + 10;
const int MAXT = 500 + 10;

vector<pair<int, int>> peias[MAXN];
int sapatos[MAXT];

ll memo[MAXN][MAXN*MAXK];

ll solve(int t) {
    int n = peias[t].size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sapatos[t]; j++) 
            memo[i][j] = -1;

    function<ll(int, int)> dp = [&] (int i, int k) {
        if (i == n) return 0ll;
        ll& res = memo[i][k];
        if (res != -1) 
            return res;

        res = dp(i + 1, k);
        if (k >= peias[t][i].f)
            res = max(res, peias[t][i].s + dp(i + 1, k - peias[t][i].f));

        return res;
    };

    return dp(0, sapatos[t]);
}

int main() {
    int N, T; cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int ki, ti, mi; cin >> ki >> ti >> mi;
        ki /= 2;
        peias[ti].push_back({ki, mi});
    }

    for (int i = 1; i <= T; i++) {
        int l, r; cin >> l >> r;
        sapatos[i] = min(l, r);
    }

    ll res = 0;
    for (int i = 1; i <= T; i++)
        res += solve(i);
    cout << res << endl;
}
