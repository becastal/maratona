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

struct nodo {
	int z, neg;
};
namespace seg {
	nodo seg[4*MAX];
	int v[MAX], n;

	nodo comb(nodo a, nodo b) {
		return nodo(a.z + b.z, a.neg + b.neg);
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(!v[l], v[l] < 0);
		int m = (l+r)/2;
		return seg[p] = comb(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo(0, 0);
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return comb(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(!x, x < 0);
		int m = (l+r)/2;
		return seg[p] = comb(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

void solve(int n, int q) {
	for (int i = 0; i < n; i++) {
		cin >> seg::v[i];
	}
	seg::n = n;
	seg::build();

	while (q--) {
		char tp; cin >> tp;

		if (tp == 'C') {
			int i, x; cin >> i >> x; i--;
			seg::update(i, x);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			nodo res = seg::query(l, r);

			if (res.z) {
				cout << '0';
			} else if (res.neg & 1) {
				cout << '-';
			} else {
				cout << '+';
			}
		}
	}
	cout << endl;
}

int main()
{
    _;

	int n, q;
	while (cin >> n >> q) {
		solve(n, q);
	}
    
    return(0);
}
