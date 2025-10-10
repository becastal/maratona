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
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	
	auto g_ = accumulate(A.begin(), A.end(), 0, [&](int a, int b) {
		return gcd(a, b);
	});
	int c1 = 0;
	for (int& i : A) c1 += (i /= g_) == 1;
	if (c1) return cout << n - c1 << endl, 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (gcd(A[i], A[j]) == 1) return cout << n << endl, 0;
		}
	}

	map<int, int> dp;
	for (int i : A) {
		auto dp_ = dp;
		dp_[i] = 1;
		
		for (auto [g, p] : dp) {
			int g_ = gcd(g, i);
			dp_[g_] = min(dp_.count(g_) ? dp_[g_] : INF, p + 1);
		}
		dp = dp_;
	}

	cout << n - 2 + dp[1] << endl;
	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
