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

int n, Q; 
void solve() {
	vector<int> v(n);

	int tot = 0;
	for (int& i : v) cin >> i, tot += max(i, 0);
	
	vector<vector<ll>> dp(n+1, vector<ll> (tot+1, 0));
	dp[0][0] = 1;

	for (int i : v) {
		for (int j = n; j >= 1; j--) {
			for (int k = tot; k >= i; k--) {
				dp[j][k] += dp[j-1][k - i];
			}
		}
	}

	for (int q = 1; q <= Q; q++) {
		int d, m; cin >> d >> m;

		if (m > n) {
			cout << "QUERY: 0" << endl;
			continue;
		}

		ll res = 0;
		for (int i = d; i <= tot; i += d) {
			res += dp[m][i];
		}

		cout << "QUERY " << q << ": " << res << endl;
	}
}

int main()
{
    _;

	int t = 1;
	while (cin >> n >> Q and n and Q) {
		cout << "SET " << t++ << ":" << endl;
		solve();
	}
    
    return(0);
}
