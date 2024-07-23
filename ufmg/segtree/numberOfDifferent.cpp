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
typedef bitset<50> bs;

const int MAX = 1e5 + 10;

namespace seg {
	int n;
	bs seg[4 * MAX];
	int v[MAX];

	bs build(int p=1, int l=0, int r=n-1) {
		if (l == r)
		{
			bs bi; bi[v[l]] = 1;
			return seg[p] = bi;
		}
		int m = (l+r)/2;
		return seg[p] = (build(2*p, l, m) | build(2*p+1, m+1, r));
	}
	bs query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return (query(a, b, 2*p, l, m) | query(a, b, 2*p+1, m+1, r));
	}
	bs update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r)
		{
			bs bi; bi[x] = 1;
			return seg[p] = bi;
		}
		int m = (l+r)/2;
		return seg[p] = (update(i, x, 2*p, l, m) | update(i, x, 2*p+1, m+1, r));
	}
};

int main() { _;

	int n, q; cin >> n >> q; seg::n = n;
	for (int i = 0; i < n; i++)
		cin >> seg::v[i];

	seg::build();
	
	while (q--) {
		char qi; cin >> qi;
		if (qi == '1') {
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).count() << endl;
		}
		else {
			int i, x; cin >> i >> x; i--;
			seg::update(i, x);
		}
	}
    
    return(0);
}
