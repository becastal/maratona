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
	int seg[4*MAX], lazy[4*MAX], n, v[MAX];

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void prop(int p, int l, int r) {
        if(lazy[p] != 0) {
            seg[p] += lazy[p];
            if(l != r) {
                lazy[2 * p] += lazy[p];
                lazy[2 * p + 1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return -INF;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
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
};

int main()
{
    _;

	int n, m; cin >> n >> m; seg::n = n;
	for (int i = 0; i < n; i++) {
		cin >> seg::v[i];
	}
	seg::build();

	vector<int> res(m, 0);
	for (int i = 0, x; i < m; i++) {
		cin >> x;

		int idx = seg::get_left(0, n-1, x);
		res[i] = idx+1;

		if (idx != -1) {
			seg::update(idx, idx, -x);
		}
	}

	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
