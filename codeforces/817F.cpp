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

const int MAX = 3e5+10;
namespace seg {
	struct nodo {
		int uns, tam;
		nodo() : uns(0), tam(1) {};
		nodo(int a, int b) : uns(a), tam(b) {};
		friend nodo operator +(nodo a, nodo b) {
			return nodo(a.uns + b.uns, a.tam + b.tam);
		};
	};
	nodo seg[4*MAX];
	int lazy[4*MAX], lazyf[4*MAX];
	int n, *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1, lazyf[p] = 0;
		if (l == r) return seg[p] = nodo();
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (lazy[p] != -1) {
			seg[p].uns = lazy[p] * seg[p].tam;
			if (l < r) {
				lazy[2*p] = lazy[2*p+1] = lazy[p];
				lazyf[2*p] = lazyf[2*p+1] = 0;
			}
			lazy[p] = -1;
		}

		if (lazyf[p]) {
			seg[p].uns = seg[p].tam - seg[p].uns;
			if (l < r) {
				auto f = [&](int i) {
					if (lazy[i] != -1) lazy[i] ^= 1;
					else lazyf[i] ^= 1;
				};
				f(2*p);
				f(2*p+1);
			}
			lazyf[p] = 0;
		}
	}
	nodo set(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = set(a, b, x, 2*p, l, m) + set(a, b, x, 2*p+1, m+1, r);
	}
	nodo xora(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazyf[p] ^= 1;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = xora(a, b, 2*p, l, m) + xora(a, b, 2*p+1, m+1, r);
	}
	int left(int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (seg[p].uns == seg[p].tam) return -1;
		if (l == r) return l;

		int m = (l+r)/2;
		prop(2*p, l, m), prop(2*p+1, m+1, r);
		if (seg[2*p].uns < seg[2*p].tam) return left(2*p, l, m);
		return left(2*p+1, m+1, r);
	}
};
int solve() {
	int n; cin >> n;

	vector<array<ll, 3>> Q(n);

	vector<ll> A;
	ll mn = 1, mx = 0;
	for (auto& [tp, l, r] : Q) {
		cin >> tp >> l >> r;
		A.push_back(l);
		A.push_back(r+1);
		mn = min(mn, l);
		mx = max(mx, r+1);
	}

	A.push_back(mn), A.push_back(mx);
	vector<ll> B(A);
	sort(all(B));
	B.erase(unique(all(B)), B.end());
	for (auto& [tp, l, r] : Q) {
		l = lower_bound(all(B), l) - B.begin();	
		r = lower_bound(all(B), r+1) - B.begin()-1;	
	}

	int m = B.size();
	vector<int> zero(m, 0);
	seg::build(m, zero.data());

	for (auto [tp, l, r] : Q) {
		if (tp == 1) {
			seg::set(l, r, 1);
		} else if (tp == 2) {
			seg::set(l, r, 0);
		} else if (tp == 3) {
			seg::xora(l, r);
		}
		
		cout << B[seg::left()] << endl;
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
