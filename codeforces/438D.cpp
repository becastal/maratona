#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e5+10;
namespace seg {
	struct nodo {
		ll soma, mx, mn;
		nodo() : soma(0), mx(0), mn(0) {};
		nodo(ll a) : soma(a), mx(a), mn(a) {};
		nodo(ll a, ll b, ll c) : soma(a), mx(b), mn(c) {};
		friend nodo operator +(nodo a, nodo b) { 
			return nodo(a.soma + b.soma, max(a.mx, b.mx), min(a.mn, b.mn));
		};
	};
	nodo seg[4*MAX];
	ll lazy[4*MAX];
	int n, *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (lazy[p] == -1) return;

		seg[p].soma = lazy[p] * (r - l + 1);
		seg[p].mx = seg[p].mn = lazy[p];
		if (l != r) lazy[2*p] = lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return nodo(0);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p].mx < x) return seg[p];
		if (l == r) return seg[p] = nodo(seg[p].soma % x);

		if (a <= l and r <= b and seg[p].mx == seg[p].mn) {
			lazy[p] = seg[p].mx % x;
			prop(p, l, r);
			return seg[p];
		}
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
	nodo set(int i, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(x);
		int m = (l + r) / 2;
		return seg[p] = set(i, x, 2*p, l, m) + set(i, x, 2*p+1, m+1, r);
	}
};


int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	
	seg::build(n, A.data());
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int l, r;  cin >> l >> r; l--, r--;
			cout << seg::query(l, r).soma << endl;
		} else if (tp == 2) {
			int l, r, x;  cin >> l >> r >> x; l--, r--;
			seg::update(l, r, x);	
		} else {
			int i, x; cin >> i >> x; i--;
			seg::set(i, x);
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
