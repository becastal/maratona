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


const int MAX = 5e5+10;
namespace seg {
	struct nodo {
		char pref, suf;
		int cpref, csuf, res, tam;

		nodo() : pref('$'), suf('$'), cpref(0), csuf(0), res(0), tam(0) {};
		nodo(char c) : pref(c), suf(c), cpref(1), csuf(1), res(1), tam(1) {};
		friend nodo operator+(nodo a, nodo b) {
			if (a.pref == '$') return b;
			if (b.pref == '$') return a;

			nodo c;
			c.tam = a.tam + b.tam;
			c.pref = a.pref;
			c.suf = b.suf;
			c.res = max(a.res, b.res);
			
			if (a.suf == b.pref) c.res = max(c.res, a.csuf + b.cpref);
			c.cpref = a.cpref + ((a.cpref == a.tam) and (a.suf == b.pref) ? b.cpref : 0);
			c.csuf = b.csuf + ((b.csuf == b.tam) and (a.suf == b.pref) ? a.csuf : 0);
			return c;
		};
	};
	nodo seg[4*MAX];
	int n;
	char *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, char* v2) {
		n = n2, v = v2;
		build();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return nodo();
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int i, char x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo(x);
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<char> S(n);
	for (char& c : S) cin >> c;

	seg::build(n, S.data());
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int i; cin >> i; i--;
			char c; cin >> c;
			seg::update(i, c);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).res << endl;
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
