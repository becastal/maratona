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
typedef pair<ll, ll> ii;
const int mod = 998244353;

struct nodo {
	int tam, a, b, ab;
}

namespace seg {
	nodo seg[4*MAX], lazy[4*MAX];
	vector<nodo> v;
	int n;

	nodo combina (nodo& u, nodo& v) {
		nodo w;
		w.tam = u.tam + v.tam; w.a = u.a + v.a;
		w.a = u.a + v.a;
		w.b = u.b + v.b;
		w.ab = u.ab + v.ab;
		w.tam %= mod, w.b %= mod, w.b %= mod, w.ab %= mod;
		return w;
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) {
			lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
			lazy[2*p] %= mod, lazy[2*p+1] %= mod;
		}
		lazy[p] = 0;
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	int n, q; cin >> n >> q; seg::n = n;
	seg::v.resize(n);
	for (nodo& i : v) cin >> i.a, i.tam = 1;
	for (nodo& i : v) cin >> i.b, i.ab = i.a * i.b % mod;
	
	seg::build();

	while (q--) {
		char qi; cin >> qi;
		if (qi == '1') {
			int l, r, x; cin >> l >> r >> x;
			
		} else if (qi == '2') {
			int l, r, x; cin >> l >> r >> x;
			
		} else {
			int l, r; cin >> l >> r;
			cout << seg::query(l-1, r-1).ab << endl;
		}
	}
    
    return(0);
}
