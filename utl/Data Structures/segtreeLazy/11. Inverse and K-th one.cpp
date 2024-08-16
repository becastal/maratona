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

// cada nodo guarda a quantidade de uns que ele olha. atualizar eh facil porque eh so inverter;
// query eh mais dificil
namespace seg {
	int seg[4*MAX], lazy[4*MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void prop(int p, int l, int r) {
		if (lazy[p] & 1) {
			lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
			seg[p] = (r-l+1)-seg[p];
		}
		lazy[p] = 0;
	}
	int query(int k, int p=1, int l=0, int r=n-1) {
		prop(p, l, r), prop(2*p, l, r), prop(2*p+1, l, r);
		if (l == r) return l;
		int m = (l+r)/2;
		if (seg[p] >= k) {
			query(query(k, 2*p+1, m+1, r)
		}

		return query(k, 2*p, l, m) + query(k, 2*p+1, m+1, r);
	}
	int update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += 1;
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

	int n, m; cin >> n >> m; seg::n = n;

	while (m--) {
		char tp; cin >> tp;
		int l, r, k;

		if (tp == 1) {
			cin >> l >> r; r--;	
			seg::update(l, r);
		} else {
			cin >> k;	
			cout << seg::query(k) << endl;
		}
	}
    
    return(0);
}
