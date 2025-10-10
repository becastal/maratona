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
        ll sum, pref, suf, val;
        int len;
		nodo() {};
		nodo(int l, ll v)  {
			len = l;
			sum = v * l;
			pref = suf = val = max(0LL, sum);
		}
    };
 
    nodo seg[4*MAX];
    int n, *v;
 
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
        if (l == r) return seg[p] = nodo(1, v[l]);
        int m = (l + r) / 2;
        return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
    }
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo(0, 0);	
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
}
 
int solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int& i : a) cin >> i;
 
	seg::build(n, a.data());
 
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		cout << seg::query(l, r).val << endl;
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
