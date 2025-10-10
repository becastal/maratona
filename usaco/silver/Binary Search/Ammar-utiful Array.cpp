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

	vector<vector<int>> c((int)2e5+10);
	vector<int> a(n), c_(n);
	for (int& i : a) cin >> i;
	for (int& i : c_) cin >> i;

	for (int i = 0; i < n; i++) {
		c[c_[i]].push_back(a[i]);
	}

	for (auto& v : c) {
		for (int i = 1; i < (int)v.size();	i++) {
			v[i] += v[i-1];
		}
	}

	ll upd = 0;
	vector<ll> dif(2e5+10, 0);
	int q; cin >> q;

	while (q--) {
		int tp, col; cin >> tp >> col;

		if (tp == 1) {
			ll x; cin >> x;
			upd += x;
			dif[col] += x;
		} else {
			ll add = upd - dif[col], y; cin >> y;
			auto& v = c[col];

			int l = 0, r = (int)v.size(), res = 0;
			while (l <= r) {
				int m = l + (r - l) / 2;

				ll orig = (m > 0 ? v[m-1] : 0);

				if (orig + m * add <= y) {
					l = m+1;	
					res = m;
				} else {
					r = m-1;	
				}
			} 

			cout << res << endl;
		}
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
