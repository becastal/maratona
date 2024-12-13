#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

    int xi, S = 0;
    vector<int> v;

    while (cin >> xi) {
        v.push_back(xi), S += xi;
		char c; cin >> c;
    }

    int n = (int)v.size();

    vector<vector<ll>> dpa(n+1, vector<ll>(S+1, 0LL)), dpb(n+1, vector<ll>(S+1, 0LL));

    auto moneysums = [&](vector<vector<ll>>& dp, int ordem) {
        if (ordem) sort(v.begin(), v.end());
        else sort(v.rbegin(), v.rend());

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= S; j++) {
                dp[i][j] = dp[i-1][j];
                int ult = j - v[i-1];
                if (ult >= 0) {
                    dp[i][j] += dp[i-1][ult];
                }
            }
        }
    };

    moneysums(dpa, 1);
    moneysums(dpb, 0);

    ll res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= S; j++) {
			res += dpa[i][j] * dpb[n - i][j];
		}
	}

    cout << res << endl;

    return 0;
}

