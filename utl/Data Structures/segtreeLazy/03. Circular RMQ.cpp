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

const int MAX = 2 * 1e5 + 10;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	vector<int> v;
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a) return LINF;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};


int main()
{
    _;

	int n; cin >> n; seg::n = n;
	seg::v.resize(n);
	for (int& i : seg::v)
		cin >> i;

	seg::build();
	int m; cin >> m;
	while (m--) {
		int l, r; cin >> l >> r;
		if (cin.peek() == '\n' or cin.eof()) {
			if (l <= r) cout << seg::query(l, r) << endl;
			else cout << min(seg::query(0, r), seg::query(l, n-1)) << endl;	
		} else {
			int v; cin >> v;
			if (l <= r) seg::update(l, r, v);
			else seg::update(0, r, v), seg::update(l, n-1, v);
		}
	}
    
    return(0);
}
