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

void solve(int n, int k) {
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<ll>> dp(n, vector<ll>(k, 0));
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int ii = 0; ii < k-1; ii++) {
				if (v[i] <= v[j]) continue;
				dp[i][ii+1] += dp[j][ii];
			}
		}
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += dp[i][k-1];
	}
	cout << res << endl;

}

int main()
{
    _;

	int n, k; 
	while (cin >> n >> k and n) {
		solve(n, k);
	}
    
    return(0);
}
