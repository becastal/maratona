// segtree com lazy propagation
// 
// mesma coisa da com point update, mas essa permite update em um range.
// o lazy eh porque ele so da update quando precisa, stackando os updates anteriores.
// portanto, o que ta no lazy tem que ser associativo tambem.
//
// build: o(n);
// prop: o(1), atualiza valores do nodo;
// query: o(logn), soma de [a, b];
// update: o(logn), soma x em [a, b];

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

// em uma seg de max, acha primeiro i que v[i] >= val;
int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
	prop(p, l, r);
	if (b < l or r < a or seg[p] < val) return -1;
	if (r == l) return l;
	int m = (l+r)/2;
	int x = get_left(a, b, val, 2*p, l, m);
	// para ultimo i, int x = get_right(a, b, val, 2*p+1, m+1, r);
	if (x != -1) return x;
	return get_left(a, b, val, 2*p+1, m+1, r);
}
