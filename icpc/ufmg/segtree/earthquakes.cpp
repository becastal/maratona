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
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = INF;
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
	int quebra(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b and seg[p] > x) return 0;
		if (l == r)
		{
			if (seg[p] and seg[p] <= x) {
				update(l, INF);
				return 1;
			}
			else return 0;
		}
		int m = (l+r)/2;	
		return quebra(a, b, x, 2*p, l, m) + quebra(a, b, x, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	seg::n = n;
	seg::build();

	while (m--) {
		char qi; cin >> qi;
		if (qi == '1') {
			int i, h; cin >> i >> h;
			seg::update(i, h);
		} else {
			int l, r, p; cin >> l >> r >> p; r--;
			cout << seg::quebra(l, r, p) << endl;
		}
	}
    
    return(0);
}

