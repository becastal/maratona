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
	int seg[4*MAX];
	vector<int> v;
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = max(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
	int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_left(a, b, val, 2*p, l, m);
		if (x != -1) return x;
		return get_left(a, b, val, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m; seg::n = n;
	seg::v.resize(n);
	for (int& i : seg::v)
		cin >> i;

	seg::build();

	while (m--) {
		char qi; cin >> qi;
		if (qi == '1') {
			int i, v; cin >> i >> v;
			seg::update(i, v);
		} else {
			int x, l; cin >> x >> l;
			cout << seg::get_left(l, n - 1, x) << endl;
		}
	}
    
    return(0);
}
