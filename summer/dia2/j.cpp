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

const int MAX = 100010;
namespace seg {
	struct nodo {
		double L, R;
		nodo() : L(1.0), R(0.0) {}
		nodo(double L_, double R_) : L(L_), R(R_) {}

		friend nodo operator +(nodo a, nodo b) { 
			double d = 1.0 - a.R * b.L;
			nodo c(
				a.L / d,
				(a.R * b.R) / d
			);
			return c;
		}
	};
	nodo seg[4*MAX];
	double v[MAX];
	int n;

	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(1.0 - v[l], v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo();
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int i, double x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(1.0 - x, x);
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q; seg::n = n;
	for (int i = 0, ai, bi; i < n; i++) {
		cin >> ai >> bi;
		seg::v[i] = double(ai) / bi;
	}
	seg::build();	

	cout << fixed << setprecision(13);
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int i, ai, bi; cin >> i >> ai >> bi; i--;
			seg::update(i, double(ai) / bi);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).R << endl;
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
