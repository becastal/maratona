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
    int seg[4*MAX], lazy[4*MAX], n;

    int build(int p=1, int l=0, int r=n-1) {
        lazy[p] = 0;
        if (l == r) return seg[p] = 0;
        else {
            int m = (l + r) / 2;
            return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
        }
    }

    void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
    }

    int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (b < l or r < a) return seg[p];
        if (a <= l and r <= b) {
            lazy[p] += x;
            prop(p, l, r);
            return seg[p];
        }
        int m = (l + r) / 2;
        return seg[p] = max(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
    }

    int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (b < l or r < a or seg[p] < val) return -1;
        if (l == r) return l;
        int m = (l + r) / 2;
        int x = get_left(a, b, val, 2*p, l, m);
        if (x != -1) return x;
        return get_left(a, b, val, 2*p+1, m+1, r);
    }
};
int main()
{
    _;

	int n, m; cin >> n >> m; seg::n = n;

	seg::build();
	while (m--) {
		char tp; cin >> tp;
		if (tp == '1') {
			int l, r, x; cin >> l >> r >> x; r--;
			seg::update(l, r, x);
		} else { 
			int x, l; cin >> x >> l;
			cout << seg::get_left(l, n - 1, x) << endl;
		}
	}
    
    return(0);
}
