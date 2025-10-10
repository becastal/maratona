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
	int n, f, s; cin >> n >> f >> s;
	vector<int> a(n), b(n), pa(n), pb(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		pa[a[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i]; b[i]--;
		pb[b[i]] = i;
	}

	ll res = LINF;
	for (int l = 0, r; l < n; l = r) {
		int d = pb[a[l]] - l;

		r = l + 1;
		while (r < n and pb[a[r]] - r == d) {
			r++;	
		}

		int l_ = pb[a[l]], r_ = l_ + r - l;
		res = min(res, max(ll(l + l_) * f, ll(2 * n - r - r_) * s));

		//cout << l << ' ' << r-1 << endl;
		//cout << l_ << ' ' << r_-1 << endl;
		//dbg((l + l_) * f);
		//dbg((2 * n - r - r_) * s);
		//cout << endl;
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
