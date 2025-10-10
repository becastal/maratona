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
	ll k; cin >> k;

	vector<ll> v(n);
	for (ll& i : v) cin >> i;
	sort(v.begin(), v.end());

	vector<ll> pre(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1];
	}

	auto da = [&](int m) {
		//dbg(m);

		for (int l = 0; l < n; l++) {
			int r = lower_bound(v.begin(), v.end(), v[l] + m) - v.begin();

			ll esq = l * v[l] - pre[l];			
			ll dir = (pre[n] - pre[r]) - (ll)(n - r) * (v[l] + m);

			//if (m == 1) cout << "(" << l << ' ' << r << "): " << esq << ", " << dir << endl;
			if (esq + dir <= k) return 1;
		}

		for (int r = n-1; r >= 0; r--) {
			int l = lower_bound(v.begin(), v.end(), v[r] - m) - v.begin();

			ll esq = l * (v[r] - m) - pre[l];			
			ll dir = (pre[n] - pre[r+1]) - (ll)(n - (r+1)) * v[r];
			if (esq + dir <= k) return 1;
		}

		return 0;
	};

	int l = 0, r = (int)1e9+100;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;
		} else {
			l = m+1;
		}
	}

	cout << l << endl;

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
