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
	vector<int> seg;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = LLONG_MIN;	
		int m = (l + r) / 2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	Segtree(int n_) : n(n_) {
		seg = vector<int>(4 * n);
		build(1, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (r < a or l > b) return LLONG_MIN;
		if (a <= l and r <= b) return seg[p];
		int m = (l + r) / 2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int query(int a, int b) {
		return query(a, b, 1, 0, n-1);
	}
	int update(int i, int x, int p, int l, int r) {
		if (r < i or l > i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l + r) / 2;
		return seg[p] = max(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
	int update(int i, int x) {
		return update(i, x, 1, 0, n-1);
	}
};

int solve() {
	int n, c, m; cin >> n >> c >> m;

	Segtree esq(n), dir(n);
	esq.update(0, 0);
	dir.update(0, 0);

	for (int i = 0, t, p; i < m; i++) { 
		cin >> t >> p; t--;

		int qt = esq.query(t, t), dpt = LLONG_MIN;
		if (qt != LLONG_MIN) {
			dpt = esq.query(t, t) - c * t;
		}
		
		int qe = esq.query(0, t);
		if (qe != LLONG_MIN) {
			dpt = max(dpt, qe + p - c * t);
		}

		int qd = dir.query(t, n-1);
		if (qd != LLONG_MIN) {
			dpt = max(dpt, qd + p + c * t);
		}

		esq.update(t, dpt + c * t);
		dir.update(t, dpt - c * t);
	}

	int res = LLONG_MIN;
	for (int i = 0; i < n; i++) { 
		int q = esq.query(i, i);
		if (q != LLONG_MIN) {
			res = max(res, esq.query(i, i) - c * i);	
		}
	}
	cout << res << endl;

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

