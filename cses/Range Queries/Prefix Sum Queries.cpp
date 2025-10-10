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
namespace seg {
	struct nodo {
		ll soma, pref;
		nodo() {};
		nodo(ll s_, ll p_) : soma(s_), pref(p_) {};
	};
	nodo seg[4*MAX];
	ll* v;
	int n;

	nodo combina(nodo a, nodo b) {
		return nodo(a.soma + b.soma, max(a.pref, a.soma + b.pref));
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l], v[l]);
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n_, ll* v_) {
		n = n_, v = v_;
		build();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo(0, -INF);
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(x, x);
		int m = (l+r)/2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<ll> a(n);

	for (ll& i : a) cin >> i;
	seg::build(n, a.data());

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int k, u; cin >> k >> u; k--;
			seg::update(k, u);
		} else {
			int a, b; cin >> a >> b; a--, b--;
			cout << max(0LL, seg::query(a, b).pref) << endl;
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
