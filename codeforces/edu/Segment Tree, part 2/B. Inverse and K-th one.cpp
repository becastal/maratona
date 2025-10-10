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

const int MAX = 100100;
namespace seg {
    struct nodo {
        int zeros, uns;
		nodo() : zeros(0), uns(0) {};
		nodo(int z, int u) : zeros(z), uns(u) {};
    };
 
    nodo seg[4*MAX];
	ll lazy[4*MAX];
    int n, *v;
 
	nodo combina(nodo a, nodo b) {
        return nodo(a.zeros + b.zeros, a.uns + b.uns);
    }
    nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
        if (l == r) return seg[p] = nodo(!v[l], v[l]);
        int m = (l + r) / 2;
        return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
    }
	void prop(int p, int l, int r) {
        if (!lazy[p]) return;

		if (l != r) {
			lazy[2*p] ^= 1;
			lazy[2*p+1] ^= 1;
		}
		
		swap(seg[p].zeros, seg[p].uns);
		lazy[p] = 0;
	}
    nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a) return nodo(0, 0);	
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
	nodo update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			lazy[p] ^= 1;
			prop(p, l, r);
			return seg[p];
		}
		int m = (l + r) / 2;
		return seg[p] = combina(update(a, b, 2*p, l, m), update(a, b, 2*p+1, m+1, r));
	}
	int kth(int k, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (l == r) return l;			

		int m = (l + r) / 2;
		prop(2*p, l, m);
		prop(2*p+1, m+1, r);

		if (k <= seg[2*p].uns) {
			return kth(k, 2*p, l, m);
		} else {
			return kth(k - seg[2*p].uns, 2*p+1, m+1, r);
		}
	};
}

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(n, 0);
	seg::build(n, A.data());

	while (m--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int l, r; cin >> l >> r; r--;
			seg::update(l, r);
		} else {
			int k; cin >> k;
			cout << seg::kth(++k) << endl;
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
