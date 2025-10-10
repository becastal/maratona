#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<array<int, 3>> A(n);
	vector<int> B;
	for (auto& [l, r, p] : A) {
		cin >> l >> r >> p;
		B.push_back(l);
		B.push_back(r);
	}

	sort(all(B));
	B.erase(unique(all(B)), B.end());

	int m = B.size();
	vector<vector<array<int, 2>>> L(m);
	for (auto& [l, r, p] : A) {
		l = lower_bound(all(B), l) - B.begin();
		r = lower_bound(all(B), r) - B.begin();
		L[r].push_back({l, p});
	}

	vector<ll> dp(m+1, 0);
	for (int i = 1; i <= m; i++) {
		dp[i] = dp[i-1];

		for (auto [l, p] : L[i-1]) {
			dp[i] = max(dp[i], dp[l] + p);
		}
	}
	cout << dp[m] << endl;

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

