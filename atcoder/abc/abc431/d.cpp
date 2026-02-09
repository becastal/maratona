#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const ll LINF = 1e18+10;

/*
com certeza dpzinha

dp[i]: qual a melhor felicidade que eu consigo com 
valor de peso (cabeca - corpo) = i
*/

int solve() {
	int n; cin >> n;

	vector<int> W(n), A(n), B(n);

	for (int i = 0; i < n; i++) {
		cin >> W[i] >> A[i] >> B[i];
	}

	int m = accumulate(all(W), 0);
	auto id = [m](int a) {
		return a + m;
	};

	vector<ll> dp(2*m+1, -LINF);
	dp[id(0)] = 0;

	for (int i = 0; i < n; i++) {
		vector<ll> dp_(2*m+1, -LINF);

		for (int w = -m; w + W[i] <= m; w++) {
			dp_[id(w + W[i])] = max(dp_[id(w + W[i])], dp[id(w)] + B[i]);
		}

		for (int w = -m + W[i]; w <= m; w++) {
			dp_[id(w - W[i])] = max(dp_[id(w - W[i])], dp[id(w)] + A[i]);
		}

		dp = move(dp_);
	}

	ll res = -LINF;
	for (int i = 0; i <= m; i++) {
		res = max(res, dp[id(i)]);
	}
	cout << res << endl;

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

