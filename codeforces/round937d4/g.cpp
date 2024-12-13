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

void solve() {
	int n; cin >> n;
	vector<int> s(n), g(n);
	vector<string> A(n), B(n), vals;

	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		vals.push_back(a), vals.push_back(b);
		A[i] = a, B[i] = b;
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	for (int i = 0; i < n; i++) {
		s[i] = lower_bound(vals.begin(), vals.end(), A[i]) - vals.begin();
		g[i] = lower_bound(vals.begin(), vals.end(), B[i]) - vals.begin();
	}
	
	vector dp(1 << n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}

    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int lst = 0; lst < n; ++lst) {
            if(!dp[mask][lst]) continue;

            for(int i = 0; i < n; ++i) {
                if(mask >> i & 1) continue;
                if(s[lst] == s[i] || g[lst] == g[i]) {
                    dp[mask | (1 << i)][i] |= dp[mask][lst];
                }
            }
        }
    }

	int res = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			res = max(res, dp[mask][i] * __builtin_popcount(mask));
		}
	}

	cout << n - res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
