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
	int n, k; cin >> n >> k;

	int x_, a_, b_, c_; cin >> x_ >> a_ >> b_ >> c_;
	vector<ll> a(n); a[0] = x_;
	for (int i = 1; i < n; i++) {
		a[i] = ((a_ * a[i-1] % c_) + b_) % c_;
	}

	deque<pair<int, int>> dq;
	for (int i = 0; i < k; i++) {
		while (dq.size() and dq.back().f >= a[i]) {
			dq.pop_back();
		}
		dq.emplace_back(a[i], i);
	}

	int res = dq.front().f;
	for (int i = k; i < n; i++) {
		while (dq.size() and dq.back().f >= a[i]) {
			dq.pop_back();
		}

		dq.emplace_back(a[i], i);
		while (dq.front().s <= i - k) {
			dq.pop_front();
		}

		res ^= dq.front().f;
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
