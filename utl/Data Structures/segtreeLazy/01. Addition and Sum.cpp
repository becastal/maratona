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

const int MAX = 1e5 + 10;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;

	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
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
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m; seg::n = n;

	while (m--) {
		char qi; cin >> qi;
		if (qi == '1') {
			int l, r, v; cin >> l >> r >> v;
			seg::update(l, r-1, v);
		} else {
			int l, r; cin >> l >> r;
			cout << seg::query(l, r-1) << endl;
		}
	}
    
    return(0);
}
