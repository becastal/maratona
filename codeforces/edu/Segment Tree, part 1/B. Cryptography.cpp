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
	struct nodo {
		int m[2][2];
		nodo() {
			m[0][0] = m[1][1] = 1;	
			m[1][0] = m[0][1] = 0;	
		};
		nodo(int a, int b, int c, int d) {
			m[0][0] = a, m[0][1] = b;
			m[1][0] = c, m[1][1] = d;
		};
		void printa() {
			cout << m[0][0] << ' ' << m[0][1] << endl;
			cout << m[1][0] << ' ' << m[1][1] << endl << endl;
		}
	};
	nodo seg[4*MAX], *v;
	int n, r;

	nodo combina(nodo a, nodo b) {
		return nodo(
			(a.m[0][0] * b.m[0][0] % r + a.m[0][1] * b.m[1][0] % r) % r,
			(a.m[0][0] * b.m[0][1] % r + a.m[0][1] * b.m[1][1] % r) % r,
			(a.m[1][0] * b.m[0][0] % r + a.m[1][1] * b.m[1][0] % r) % r,
			(a.m[1][0] * b.m[0][1] % r + a.m[1][1] * b.m[1][1] % r) % r
		);
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n_, int r_, nodo* v_) {
		n = n_, r = r_, v = v_;
		build();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo();
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

int solve() {
	int r, n, m; cin >> r >> n >> m;

	vector<seg::nodo> A(n);
	for (int i = 0, a, b, c, d; i < n; i++) {
		cin >> a >> b >> c >> d;
		A[i] = seg::nodo(a, b, c, d);
	}
	seg::build(n, r, A.data());

	while (m--) {
		int l, r; cin >> l >> r; l--, r--;
		seg::query(l, r).printa();
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
