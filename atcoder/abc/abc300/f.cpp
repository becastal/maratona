#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll n, m, k; cin >> n >> m >> k;
	string S; cin >> S;
	vector<int> P(n+1, 0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] + (S[i-1] == 'x');	
	}

	auto da = [&](ll mid) {
		ll s = (mid / n) * P[n] + P[mid % n], mn = s;

		ll mx = n * m - mid;
		for (int i = 0; i < min(n-1, mx) and mn > k; ++i) {
			s -= (S[i] == 'x');
			s += (S[(i + mid) % n] == 'x');
			mn = min(mn, s);
		}
		return mn <= k;
	};

	ll l = 1, r = n * m, res = 1;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (da(mid)) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
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

