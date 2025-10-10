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

int solve() {
	int n, c; cin >> n >> c;
	vector<ll> a(n-1), b(n-1), pa(n, 0), pb(n, 0), pa_(n), pb_(n);

	for (ll& i : a) cin >> i;
	for (ll& i : b) cin >> i;

	for (int i = 1; i < n; i++) {
		pa[i] = pa[i-1] + a[i-1];
		pb[i] = pb[i-1] + b[i-1];
	}

	vector<ll> dp(n, INF);
	dp[0] = 0;

	//for (int i = 1; i <= n; i++) {
	//	for  (int j = 0; j < i; j++) {
	//		dp[i] = min({dp[i], 
	//					pa[i] - pa[j] + dp[j],
	//					pb[i] - pb[j] + dp[j] + c});
	//	}
	//}

	for (int i = 1; i < n; i++) {
		dp[i] = min({dp[i],
					pa[i] + pa_[i-1],
					pb[i] + pb_[i-1] + c});

		pa_[i] = min(pa_[i-1], dp[i] - pa[i]);
		pb_[i] = min(pb_[i-1], dp[i] - pb[i]);
	}

	for (int i : dp) cout << i << ' '; cout << endl;

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
