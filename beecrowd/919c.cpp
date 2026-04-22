#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Segtree {
	int n;
	vector<int> seg, v;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = (1 << v[l]);
		int m = (l + r) / 2;
		return seg[p] = build(2*p, l, m) | build(2*p+1, m+1, r);
	}
	Segtree (int n_, vector<int>& V_) : n(n_), v(V_) {
		seg = vector<int>(4 * n);
		build(1, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (a <= l and r <= b) return seg[p];
		if (a > r or b < l) return 0LL;
		int m = (l + r) / 2;
		return query(a, b, 2*p, l, m) | query(a, b, 2*p+1, m+1, r);
	}
	int query(int l, int r) {
		return query(l, r, 1, 0, n-1);
	}
	int update(int i, int x, int p, int l, int r) {
		if (r < i or l > i) return seg[p];
		if (l == r) return seg[p] = (1LL << x);
		int m = (l + r) / 2;
		return seg[p] = update(i, x, 2*p, l, m) | update(i, x, 2*p+1, m+1, r);
	}
	int update(int i, int x) {
		return update(i, x, 1, 0, n-1);
	}
};

int solve() {
	int n, q, m; cin >> n >> q >> m;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	Segtree Seg(n, A);
	for (int i = 0, tp; i < q; i++) {
		cin >> tp;
		if (tp == 1) {
			int l, r; cin >> l >> r; l--, r--;
			cout << __builtin_popcountll(Seg.query(l, r)) << endl;
		} else {
			int p, x; cin >> p >> x; p--;
			Seg.update(p, x);
		}
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

