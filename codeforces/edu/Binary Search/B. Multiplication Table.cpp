#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	ll n, k; cin >> n >> k;

	vector<ll> A(n), B(n);
	iota(A.begin(), A.end(), 1LL);
	iota(B.begin(), B.end(), 1LL);

	auto da = [&](ll mid) {
		ll res = 0;
		for (int l = 0, r = n-1; l < n; l++) {
			while (r >= 0 and A[l] * B[r] > mid) {
				r--;
			}
			if (r < 0) break;

			res += (r + 1);
		}
		return res >= k;
	};

	ll l = 1, r = n * n, res = r;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (da(mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
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
