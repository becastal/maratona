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
	int seg[4*MAX], lazy[4*MAX], setar[4*MAX], v[MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0, setar[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) ^ build(2*p+1, m+1, r);
	}
	void apply(int p, int l, int r, int x) {
        seg[p] = (((r - l + 1) & 1) ? x : 0);
        lazy[p] = x;
        setar[p] = 1;
    }
	void prop(int p, int l, int r) {
		if (!setar[p] or l == r) return;
		int m = (l+r)/2;
		apply(2*p, l, m, lazy[p]);
		apply(2*p+1, m+1, r, lazy[p]);
		setar[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) ^ query(a, b, 2*p+1, m+1, r);
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			apply(p, l, r, x);
			return seg[p];
		}
		prop(p, l, r);
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) ^ update(a, b, x, 2*p+1, m+1, r);
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
		int l, r, x; cin >> l >> r >> x; l--, r--;
		seg::update(l, r, x);

		cout << (seg::query(0, n-1) ? "Possivel" : "Impossivel") << endl;
	}
    
    return(0);
}
