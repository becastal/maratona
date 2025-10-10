#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e5+10;
namespace seg {
	struct nodo {
		vector<int> B;
		nodo() : B(30, 0) {};
		nodo(int x) : B(30, 0) {
			for (int i = 0; i < 30; i++) B[i] += (x >> i & 1);	
		};
		friend nodo operator+(nodo a, nodo b) {
			nodo c;
			for (int i = 0; i < 30; i++) {
				c.B[i] = a.B[i] + b.B[i];
			}
			return c;
		};
		ll val() {
			ll res = 0;
			for (int i = 0; i < 30; i++) {
				res += B[i] * (1LL << i);
			}
			return res;
		};
	};
	nodo seg[4*MAX];
	int lazy[4*MAX];
	int n, *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;

		for (int i = 0; i < 30; i++) if (lazy[p] >> i & 1) {
			seg[p].B[i] = (r - l + 1) - seg[p].B[i];
		}

		if (l != r) lazy[2*p] ^= lazy[p], lazy[2*p+1] ^= lazy[p];
		lazy[p] = 0;
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return nodo(0);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] ^= x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n; 
	vector<int> A(n);
	for (int& i : A) cin >> i;
	seg::build(n, A.data());

	cin >> q;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).val() << endl;
		} else {
			int l, r, x; cin >> l >> r >> x; l--, r--;
			seg::update(l, r, x);
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
