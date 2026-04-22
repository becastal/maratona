#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, c; cin >> n >> c;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<int> S(1 << n);
	for (int mask = 1; mask < (1 << n); mask++){ 
		S[mask] = S[mask & (mask - 1)] + A[__builtin_ctzll(mask)];
	}

	vector<int> Dp(1 << n, LLONG_MAX);
	Dp[0] = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int sub = mask; sub; sub = mask & (sub - 1)) if (S[sub] <= c) {
			Dp[mask] = min(Dp[mask], Dp[sub ^ mask] + 1);
		}
	}
	cout << Dp[(1 << n) - 1] << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

