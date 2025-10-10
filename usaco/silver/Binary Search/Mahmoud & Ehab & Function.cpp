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
	int n, m, q; cin >> n >> m >> q;

	vector<ll> a(n), b(m);
	for (ll& i : a) cin >> i;
	for (ll& i : b) cin >> i;

	auto bi = b, bj = b;
	for (int i = 0; i < m; i++) {
		if (i & 1) bi[i] *= -1;
		else bj[i] *= -1;
	}

	bi.insert(bi.begin(), 0LL);
	bj.insert(bj.begin(), 0LL);

	for (int i = 1; i <= m; i++) {
		bi[i] += bi[i-1];
	}
	for (int i = 1; i <= m; i++) {
		bj[i] += bj[i-1];
	}

	vector<ll> B;
	for (int i = 0; i <= m - n; i++) {
		if (i & 1) B.push_back(bj[i+n] - bj[i]);
		else B.push_back(bi[i+n] - bi[i]);
	}
	sort(B.begin(), B.end());

	ll sa = 0;
	for (int i = 0; i < n; i++) {
		sa += (i & 1 ? -1LL : +1LL) * a[i];
	}

	auto f = [&]() {
		ll res = LINF;
		auto it = lower_bound(B.begin(), B.end(), sa);

		if (it != B.end()) res = min(res, abs(sa - *it));
		if (it != B.begin()) res = min(res, abs(sa - *(--it)));
		cout << res << endl;
	};

	f();
	while (q--) {
		int l, r, x; cin >> l >> r >> x;

		if ((r - l + 1) & 1) {
			sa += (l & 1 ? +x : -x);
		} 
		f();
	}

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
