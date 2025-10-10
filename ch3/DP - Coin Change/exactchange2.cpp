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
	int x, n; cin >> x >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	
	const int maxn = 10*x;
	vector<int> dp(maxn+1, INF);
	dp[0] = 0;

	for (int i : v) {
		for (int j = maxn; j >= i; j--) {
			dp[j] = min(dp[j], dp[j-i] + 1);
		}
	}
	
	for (int i = x; i <= maxn; i++) {
		if (dp[i] != INF) {
			cout << i << ' ' << dp[i] << endl;	
			return;
		}
	}

	dbg("nao eh pra chegar aqui");
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
