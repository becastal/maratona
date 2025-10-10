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

const int MAX = 2e6+10;
namespace seg {
    struct nodo {
        ll sum, pref, suf, val;
        int len;
    };
    
    nodo seg[4*MAX];
    ll lazy[4*MAX], lazyFlag[4*MAX], v[MAX];
    int n;

    nodo make_nodo(int L, ll v) {
		nodo ret;
		ret.len = L;
		ret.sum = v * L;
		ret.pref = max(0LL, ret.sum);
		ret.suf  = max(0LL, ret.sum);
		ret.val  = max(0LL, ret.sum);
		return ret;
	}
	nodo combina(nodo a, nodo b) {
        nodo c;
        c.len = a.len + b.len;
        c.sum = a.sum + b.sum;
        c.pref = max(a.pref, a.sum + b.pref);
        c.suf  = max(b.suf, b.sum + a.suf);
        c.val  = max({a.val, b.val, a.suf + b.pref});
        return c;
    }
    nodo build(int p=1, int l=0, int r=n-1) {
        lazy[p] = lazyFlag[p] = 0;
        if (l == r) return seg[p] = make_nodo(1, v[l]);
        int m = (l + r) / 2;
        return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
    }
    void prop(int p, int l, int r) {
        if (!lazyFlag[p]) return;
        int m = (l + r) / 2;

        lazy[2*p] = lazy[p];
        lazy[2*p+1] = lazy[p];
        lazyFlag[2*p] = lazyFlag[2*p+1] = 1;
        seg[2*p] = make_nodo(m - l + 1, lazy[p]);
        seg[2*p+1] = make_nodo(r - m, lazy[p]);
        lazy[p] = 0;
        lazyFlag[p] = 0;
    }
    nodo update(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (b < l or r < a) return seg[p];
        if (a <= l and r <= b) {
			lazy[p] = x;
			lazyFlag[p] = 1;
			seg[p] = make_nodo(r - l + 1, x);
			if (l != r) prop(p, l, r);
			return seg[p];
		}
		int m = (l + r) / 2;
        return seg[p] = combina(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
    }
}

int main()
{
    _;

	int n, m; cin >> n >> m; seg::n = n;
	for (int i = 0; i < n; i++) {
		cin >> seg::v[i];
	}
	seg::build();

	for (int i = 0, ii, x; i < m; i++) {
		cin >> ii >> x; ii--;
		cout << seg::update(ii, ii, x).val << endl;
	}
 
    return(0);
}
