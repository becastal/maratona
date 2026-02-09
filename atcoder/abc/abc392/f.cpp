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

const int MAX = 5e5+10;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int v[MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
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
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	int n; cin >> n; seg::n = n;
	vector<int> p(n);
	for (int& i : p) cin >> i, i--;

	for (int i = 0; i < n; i++) {
		seg::v[i] = i;
	}
	seg::build();

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = seg::query(p[i], p[i]);	
		seg::update(p[i], n-1, +1);
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[b[i]] = i;
	}

	for (int i : a) cout << i+1 << ' '; cout << endl;
    
    return(0);
}
