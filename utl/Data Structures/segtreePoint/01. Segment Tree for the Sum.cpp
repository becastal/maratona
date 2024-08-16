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
int n, m;

namespace seg {
	ll seg[4*MAX];
	vector<int> v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
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

	cin >> n >> m;	
	seg::v.resize(n);
	for (int& vi : seg::v)
		cin >> vi;

	seg::build();

	while (m--)
	{
		char qi; cin >> qi;	
		if (qi == '1')
		{
			int i, xi; cin >> i >> xi;
			seg::update(i, xi);
		}
		else
		{
			int l, r; cin >> l >> r; r--;
			cout << seg::query(l, r) << endl;
		}
	}
    
    return(0);
}
