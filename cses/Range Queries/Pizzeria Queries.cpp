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

struct seg {
	vector<int> s;
	int n, *v;

	seg(int n_, int* v_) : n(n_), v(v_), s(4*n_+10, 0) {
		build(1, 0, n-1);
	}
	int build(int p, int l, int r) {
		if (l == r) return s[p] = v[l];
		int m = (l+r)/2;
		return s[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return INF;
		if (a <= l and r <= b) return s[p];
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int query(int a, int b) { return query(a, b, 1, 0, n-1); }
	int update(int i, int x, int p, int l, int r) {
		if (i < l or r < i) return s[p];
		if (l == r) return s[p] = x;
		int m = (l+r)/2;
		return s[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
	int update(int a, int b) { return update(a, b, 1, 0, n-1); }
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> p(n), pa(n), pb(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		pa[i] = p[i] - i;
		pb[i] = p[i] + i;
	}

	seg sega(n, pa.data());
	seg segb(n, pb.data());

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int k, x; cin >> k >> x; k--;
			sega.update(k, x - k);
			segb.update(k, x + k);
		} else {
			int k; cin >> k; k--;
			cout << min(sega.query(0, k) + k, segb.query(k, n-1) - k) << endl;
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
