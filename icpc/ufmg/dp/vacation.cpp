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

int n;
int op[10010][3];
int memo[10010][3];

int dp(int i, int j)
{
    if (i == 0) return op[i][j];

    int& at = memo[i][j];
    if (at != -1) return at;

    int res = 0;
    for (int ni = 0; ni < 3; ni++)
        if (ni != j)
            res = max(res, dp(i - 1, ni) + op[i][j]);

    return at = res;
}

int main()
{
    _;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> op[i][0] >> op[i][1] >> op[i][2];

    memset(memo, -1, sizeof memo);

    cout << max({dp(n - 1, 0), dp(n - 1, 1), dp(n - 1, 2)}) << endl;

    return 0;
}

