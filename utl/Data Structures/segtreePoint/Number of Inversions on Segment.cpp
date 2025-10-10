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

const int MAX = 1e5+10;
namespace seg {
	struct nodo {
		ll cont;
		vector<ll> f;
		nodo() : cont(0), f(41, 0) {
		}
		nodo(int x) : cont(0), f(41, 0) {
			f[x] = 1;
		}
	};

	nodo seg[4*MAX];
	int v[MAX], n;

	nodo combina(nodo a, nodo b) {
		nodo c;
		c.cont = a.cont + b.cont;
		for (int i = 0; i <= 40; i++) {
			c.f[i] = a.f[i] + b.f[i];		
		}
		
		vector<ll> preb(42, 0);
		for (int i = 1; i <= 41; i++) {
			preb[i] = b.f[i-1] + preb[i-1];			
		}

		for (int i = 0; i <= 40; i++) {
			c.cont += a.f[i] * preb[i];
		}

		return c;	
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

	int n, q; cin >> n >> q; seg::n = n;
	for (int i = 0; i < n; i++) {
		cin >> seg::v[i];
	}
	seg::build();
	
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).cont << endl;
		} else {
			int i, x; cin >> i >> x; i--;
			seg::update(i, x);
		}
	}
    
    return(0);
}
