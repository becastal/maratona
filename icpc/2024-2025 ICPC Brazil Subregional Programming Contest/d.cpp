#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	
	vector<array<int, 2>> A(m);
	for (auto& [a, b] : A) cin >> a >> b;

	vector<int> dp(n+1, 0);
	dp[n] = 1;

	for (int i = n; i >= 0; i--) {
		for (auto [a, b] : A) if (i + a <= n and (i + a) % (1 << b) == 0) {
			dp[i] += dp[i + a];	
		}
	}

	cout << dp[0] << endl;
	
	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
