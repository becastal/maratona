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

const int MAX = (1 << 18);
namespace seg {
	struct nodo {
		int alt, val;
	};
	nodo seg[4*MAX];
	int n, v[MAX];

	nodo combina(nodo a, nodo b) {
		nodo c;
		c.alt = a.alt ^ 1;
		c.val = (c.alt ? a.val | b.val : a.val ^ b.val);
		return c;
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(0, v[l]);
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(0, x);
		int m = (l+r)/2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

int main()
{
    _;

	int n, q; cin >> n >> q; seg::n = (1 << n);
	for (int i = 0; i < (1 << n); i++) {
		cin >> seg::v[i];
	}
	seg::build();

	for (int i = 0, pos, x; i < q; i++) {
		cin >> pos >> x; pos--;
		cout << seg::update(pos, x).val << endl;
		//cout << seg::seg[1].val << endl;
	}
    
    return(0);
}
