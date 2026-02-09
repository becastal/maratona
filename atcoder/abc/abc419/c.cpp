#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) cin >> a >> b;

	auto da = [&](ll m) {
		ll la = LLONG_MIN, ra = LLONG_MAX, lb = LLONG_MIN, rb = LLONG_MAX;
		for (auto [a, b] : A) {
			la = max(la, a - m);
			ra = min(ra, a + m);
			lb = max(lb, b - m);
			rb = min(rb, b + m);
		}

		return (la <= ra) and (lb <= rb);
	};

	ll l = 0, r = 1e9, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;
		
		if (da(m)) {
			r = m-1;
			res = m;
		} else {
			l = m+1;
		}
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

