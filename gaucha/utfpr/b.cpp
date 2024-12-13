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

	int n, k; cin >> n >> k;

	vector<int> b(n), m(k), dp(1010, INF);
	for (int& i : b) cin >> i;
	for (int& i : m) cin >> i;

	dp[0] = 0;
	for (int i = 1; i < 1010; i++) {
		for (int j : m) {
			if (i - j >= 0) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}
	}

	int res = 0;
	for (int i : b) {
		if (dp[i] == INF) return cout << -1 << endl, 0;
		res += dp[i];
	}

	cout << res << endl;
    
    return(0);
}
