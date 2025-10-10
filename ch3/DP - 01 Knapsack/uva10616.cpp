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

int n, Q; 

void solve() {
    vector<int> v(n);

    int maxn = 0, minn = 0;
    for (int& i : v) {
        cin >> i;
        maxn += max(0, i);
        minn += min(0, i);
    }

    int offset = abs(minn);
    int range = maxn - minn + 1;

    vector<vector<ll>> dp(n + 1, vector<ll>(range, 0));
    dp[0][offset] = 1;

    for (int i : v) {
        for (int j = n; j >= 1; j--) {
            for (int k = 0; k < range; k++) {
                if (k - i >= 0 and k - i < range) {
                    dp[j][k] += dp[j-1][k-i];
                }
            }
        }
    }

	for (int q = 1; q <= Q; q++) {
		int d, m;
		cin >> d >> m;

		if (m > n) {
			cout << "QUERY " << q << ": 0" << endl;
			continue;
		}
		ll res = 0;

		for (int k = 0; k <= maxn - minn; k++) {
			if (((k + minn) % d + d) % d == 0) {
				res += dp[m][k];
			}
		}

		cout << "QUERY " << q << ": " << res << endl;
	}
}

int main() {
    _;

    int t = 1;
    while (cin >> n >> Q && n && Q) {
        cout << "SET " << t++ << ":" << endl;
        solve();
    }
    
    return 0;
}

