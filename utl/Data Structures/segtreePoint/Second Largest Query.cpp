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
		int a, fa, b, fb;
		nodo() : a(0), fa(0), b(0), fb(0) {
		}
		nodo(int x) : a(x), fa(1), b(0), fb(0) {
		}
	};
	nodo seg[4*MAX], v[MAX];
	int n;

	nodo combina(nodo A, nodo B){
		nodo C;
		if(A.a > B.a){
			C.a = A.a; C.fa = A.fa;
			int ca = A.b, cfa = A.fb;
			int da = B.a, dfa = B.fa;
			if(da > ca){ C.b = da; C.fb = dfa; }
			else if(da == ca){ C.b = ca; C.fb = cfa + dfa; }
			else{ C.b = ca; C.fb = cfa; }
		}else if(A.a < B.a){
			C.a = B.a; C.fa = B.fa;
			int ca = B.b, cfa = B.fb;
			int da = A.a, dfa = A.fa;
			if(da > ca){ C.b = da; C.fb = dfa; }
			else if(da == ca){ C.b = ca; C.fb = cfa + dfa; }
			else{ C.b = ca; C.fb = cfa; }
		}else{
			C.a = A.a; C.fa = A.fa + B.fa;
			if(A.b > B.b){ C.b = A.b; C.fb = A.fb; }
			else if(A.b < B.b){ C.b = B.b; C.fb = B.fb; }
			else{ C.b = A.b; C.fb = A.fb + B.fb; }
		}
		return C;
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo();
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(x);
		int m = (l+r)/2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

int main()
{
    _;

	int n, q; cin >> n >> q; seg:: n = n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		seg::v[i] = seg::nodo(x);
	}
	seg::build();
	
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int p, x; cin >> p >> x; p--;	
			seg::update(p, x);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).fb << endl;
		}
	}
    
    return(0);
}
