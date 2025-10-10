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

const int MAX = 2e5+10;
namespace seg {
	int seg[4*MAX], v[MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return INF;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

int solve() {
	int n; cin >> n; seg::n = n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	
	auto v_ = v;
	sort(v_.begin(), v_.end());

	vector<int> p(n), vis(n, 0);
	for (int i = 0; i < n; i++) {
		p[i] = lower_bound(v_.begin(), v_.end(), v[i]) - v_.begin();
		seg::v[p[i]] = i;
	}

	seg::build();
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		vector<int> a;
		for (int u = i; u < n; ) {
			vis[u] = 1;
			seg::update(p[u], INF);

			a.push_back(v[u]);
			int u_ = seg::query(p[u], n);
			if (u_ <= u) break;
			u = u_;
		}

		for (int i : a) cout << i << ' '; cout << endl;
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
