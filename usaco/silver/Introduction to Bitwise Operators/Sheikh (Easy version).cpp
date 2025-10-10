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
	int n, q; cin >> n >> q;

	ll s = 0, xs = 0;
	vector<int> v(n);
	for (int& i : v) {
		cin >> i;
		s += i;
		xs ^= i;
	}
	
	vector<ll> pres(n+1, 0), prexs(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pres[i] = pres[i-1] + v[i-1];
		prexs[i] = prexs[i-1] ^ v[i-1];
	}

	ll obj = s - xs;
	int l_ = -1, r_ = -1;

	auto da = [&](int m) {
		for (int i = m; i <= n; i++) {
			if ((pres[i] - pres[i-m]) - (prexs[i] ^ prexs[i-m]) == obj) {
				l_ = i-m+1, r_ = i;
				return 1;
			}
		}
		return 0;
	};

	int l, r; cin >> l >> r;
	assert(l == 1 and r == n);
	while (l <= r) {
		int m = l + (r - l) / 2;	

		if (da(m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	
	cout << l_ << ' ' << r_ << endl;

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
