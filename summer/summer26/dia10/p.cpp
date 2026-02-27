#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<typename T>
struct swag {
	stack<array<T, 2>> in, out;

	T e() { return LLONG_MIN; };
	T op(T a, T b) {
		return max(a, b);
	}
	void push(T x) {
		in.push({x, op(x, in.empty() ? e() : in.top()[1])});
	}
	void pop() {
		if (!out.empty()) {
			out.pop();
			return;
		}

		while (!in.empty()) {
			auto [a, b] = in.top(); in.pop();
			out.push({a, op(a, out.empty() ? e() : out.top()[1])});
		}
		out.pop();
	}
	T query() {
		return op(in.empty() ? e() : in.top()[1], out.empty() ? e() : out.top()[1]);
	}
	int size() { return in.size() + out.size(); };
	bool empty() { return in.empty() and out.empty(); };
};

int solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	if ((x + 1) * k < (n + 1)) return cout << -1 << endl, 0;

	vector<int> dp(n+1, LLONG_MIN), dp_(n+1, LLONG_MIN);
	dp[0] = 0;

	for (int j = 1; j <= x; j++) {
		swag<int> S;
		dp_[0] = LLONG_MIN;

		for (int i = 1; i <= n; i++) {
			S.push(dp[i-1]);
			if (S.size() > k) S.pop();
			dp_[i] = A[i-1] + S.query();
		}
		dp.swap(dp_);
		fill(all(dp_), LLONG_MIN);
	}

	//for (int i = 1; i <= n; i++) {
	//	for (int ii = 1; ii <= x; ii++) {
	//		for (int j = max(0LL, i - k); j < i; j++) {
	//			dp[i][ii] = max(dp[i][ii], A[i-1] + dp[j][ii-1]);
	//		}
	//	}
	//	res = max(res, dp[i][x]);
	//}

	int res = LLONG_MIN;
	for (int i = max(1LL, n - k + 1); i <= n; i++) {
		res = max(res, dp[i]);
	}
	cout << res << endl;

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

