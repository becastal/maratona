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

void solve() {
	ll n; cin >> n;
	vector<ll> v(n);
	for (ll& i : v) cin >> i;

	ll res = accumulate(v.begin(), v.end(), 0LL);
	auto calc = [&n, &res](vector<ll> v, ll s) {
		vector<ll> mad(n, 0), fr(n+1, 0);

		for (ll i = 0, mad_ = 0; i < n; i++) {
			if (fr[v[i]]) mad_ = max(mad_, v[i]);	

			fr[v[i]] = 1;
			mad[i] = mad_;
		}

		if (s) res += accumulate(mad.begin(), mad.end(), 0LL);
		return mad;
	};
	vector<ll> mad = calc(calc(v, 1), 0);

	for (ll l = 0, r; l < n; l = r) {
		r = l+1;

		while (r < n and mad[r] == mad[l]) {
			r++;
		}

		ll tam = r - l;
		
		res += ((1 + tam) * tam / 2) * mad[l];
		res += tam * (n - r) * mad[l];
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
