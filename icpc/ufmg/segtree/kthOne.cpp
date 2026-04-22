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
	int seg[4*MAX], lazy[4*MAX];
	vector<int> v;
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_left(a, b, val, 2*p, l, m);
		if (x != -1) return x;
		return get_left(a, b, val, 2*p+1, m+1, r);
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
};


int main()
{
    _;

	int n, m; cin >> n >> m;
	seg::n = n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	seg::v = v;
	for (int i = 1; i < n; i++)
		seg::v[i] += seg::v[i - 1];

	seg::build();

	while (m--) {
		char qi; cin >> qi;
		if (qi == '1') {
			int i; cin >> i;	
			seg::update(i, n-1, (v[i] ? -1 : +1));
			v[i] = !v[i];
		} else {
			int k; cin >> k;
			cout << seg::get_left(0, n-1, k + 1) << endl;
		}
	}
    
    return(0);
}
