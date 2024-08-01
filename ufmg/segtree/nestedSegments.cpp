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

const int MAX = 1e6 + 10;

namespace seg {
	ll seg[4*MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	int n; cin >> n; seg::n = 2*n;
	vector<int> v(2*n), vals(MAX, -1), res(n);

	for (int& i : v)
		cin >> i;

	seg::build();

	for (int i = 0; i < 2 * n; i++) {
		if (vals[v[i]] != -1) {
			int pos = vals[v[i]];
			//cout << v[i] << ": " << pos << ' ' << i << ": " << seg::query(pos, i) << endl;
			res[v[i] - 1] = seg::query(pos, i);	
			seg::update(pos, 1);
		} else {
			vals[v[i]] = i;
		}
	}


	for (int i : res)
		cout << i << ' ';
	cout << endl;
    
    return(0);
}

