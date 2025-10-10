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
		ll pre, suf, val, soma;
	};
	nodo seg[4*MAX];
	int n;

	nodo combina(nodo a, nodo b) {
		nodo c;
		c.pre = max(a.pre, a.soma + b.pre);
		c.suf = max(b.suf, b.soma + a.suf);
		c.val = max({a.val, b.val, a.suf + b.pre});
		c.soma = a.soma + b.soma;
		return c;
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo{-1, -1, -1, -1};
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo{0, 0, 0, 0};
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = nodo{x, x, x, x};
		int m = (l+r)/2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

void solve() {
	int n; cin >> n; seg::n = n;
	vector<int> v(n);
	map<int, vector<int>> M;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		M[v[i]].push_back(i);
	}
	seg::build();

	ll mx = 0, res = -1;
	for (auto [x, vi] : M) {
		for (int i : vi) seg::update(i, +1);

		int qi = seg::query(0, n-1).val;
		if (mx < qi) {
			res = x;
			mx = qi;
		}

		for (int i : vi) seg::update(i, -1);
	}

	for (int i = 0; i < n; i++) {
		v[i] = (v[i] == res ? +1 : -1);
	}

	mx = 0;
	int l = -1, r = -1;
	for (int i = 0, ultl = 0, agr = 0; i < n; i++) {
		agr += v[i];
		if (agr > mx) {
			mx = agr;
			r = i;
			l = ultl;
		}

		if (agr <= 0) {
			ultl = i+1;
			agr = 0;
		}
	}

	cout << res << ' ' << l+1 << ' ' << r+1 << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();					
	}
    
    return(0);
}
