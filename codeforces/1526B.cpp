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

int main()
{
    _;

	int maxn = 11 * 111 - 11 - 111;
	vector<int> dp(maxn+1, 0);
	dp[0] = 1;
	for (int i = 1; i <= maxn; i++) {
		for (int j : {11, 111}) {
			if (i - j >= 0) {
				dp[i] |= dp[i - j];
			}
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n > maxn) {
			cout << "YES" << endl;
			continue;
		}
		cout << (dp[n] ? "YES" : "NO") << endl;
	}
    
    return(0);
}
