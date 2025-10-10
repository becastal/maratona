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

const int maxn = 3e4+10;

void solve() {
	int x, n; cin >> x >> n;

	vector<int> v(n);
	for (int& i : v) cin >> i;
	vector<int> dp(maxn+1, INF);
	dp[0] = 0;

	for (int i : v) {
		for (int j = maxn; j >= i; j--) {
			dp[j] = min(dp[j], dp[j-i]+1);
		}
	}

	int ok = 0, i = x;
	for (i; i <= maxn and !ok; i++) {
		ok |= dp[i] != INF;
	}
	i--;

	cout << i << ' ' << dp[i] << endl;
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
