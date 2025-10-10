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

	vector<pair<ll, ll>> A(n);
	ll mn = LINF, mx = -LINF;
	for (auto& [l, r] : A) {
		cin >> l >> r;
		mn = min(mn, l);
		mx = max(mx, r);
	}

	auto da = [&](ll x) {
		vector<pair<ll, ll>> ev;
		for (ll i = 0; i < n; i++) {
			auto [l, r] = A[i];
			ev.emplace_back(l, 0);
			ev.emplace_back(r+1, 1);
		}
		ev.emplace_back(x+1, 2);
		sort(all(ev));

		ll res = 0, ult = ev[0].f, agr = 0;
		for (auto [pos, tp] : ev) {
			res += agr * (pos - ult);
			agr += (tp ? -1 : +1);
			ult = pos;
			if (tp == 2) break;
		}

		return res > k;
	};

	ll l = mn, r = mx, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			res = m;	
			r = m - 1;
		} else {
			l = m + 1;
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
