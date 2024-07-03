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
int n, m;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int v[MAX];

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
	ll update(int i, int x, int p=1, int l=0, int r=n-1)
	{
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l + r) / 2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p + 1, m + 1, r);
	}
};

int main()
{
    _;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> seg::v[i];

	seg::build();
	while (m--)
	{
		char tp; cin >> tp;
		if (tp == '1')
		{
			int i, x; cin >> i >> x;
			seg::update(i, x);
		}
		else
		{
			int l, r; cin >> l >> r; r--;
			cout << seg::query(l, r) << endl;
		}
	}
    
    return(0);
}
