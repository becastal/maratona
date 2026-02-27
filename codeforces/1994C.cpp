#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, x; cin >> n >> x;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (i) A[i] += A[i-1];
	}

	vector<int> dp(n + 1, 0);
	for (int i = n-1; i >= 0; i--) {
		// primeiro ponto que A[j] > x + A[i]
		int q = x + (i ? A[i-1] : 0);
		int j = upper_bound(A.begin() + i, A.end(), q) - A.begin();
		if (j >= n) continue;
		dp[i] = 1 + dp[j + 1];
	}

	cout << n * (n + 1) / 2 - accumulate(all(dp), 0LL) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

