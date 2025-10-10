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
	int n, k; cin >> n >> k;
	vector<int> v(n);

	for (int& i : v) cin >> i, i = abs(i) % k;
	
	vector<int> dp(2*k+1, 0);
	dp[k] = 1;

	for (int i : v) {
		vector<int> dpi(2*k+1, 0);

		for (int j = 0; j <= 2*k; j++) {
			dpi[j] |= dp[((j - k + i) % k + k) % k + k];
			dpi[j] |= dp[((j - k - i) % k + k) % k + k];
		}

		dp = move(dpi);
	}

	cout << (dp[k] ? "Divisible" : "Not divisible") << endl;
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
