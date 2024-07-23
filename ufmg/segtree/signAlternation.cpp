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
typedef pair<int, int> ii;
const int MAX = 1e5 + 10;


namespace seg {
	ii seg[4 * MAX];
	ii v[MAX];
	int n;

	ii combina(ii a, ii b) {
		return ii(a.f + b.f, a.s + b.s);
	}
	ii build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	ii query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return ii(0, 0);
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ii update(int i, ii x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

// ter uma seg em que eu consigo puxar a soma de todas as posicoes impares e todas as posicoes pares.
// se uma query comeca em uma posicao impar, entao query::impares - query::pares;
int main()
{
    _;

	int n; cin >> n; seg::n = n;
	for (int i = 0; i < n; i++) {
		seg::v[i] = ii(0, 0);
		if (i & 1)
			cin >> seg::v[i].f;
		else
			cin >> seg::v[i].s;
	}

	seg::build();

	int q; cin >> q;
	while (q--) {
		char qi; cin >> qi;
		if (qi == '0') { 
			int i, j; cin >> i >> j; i--;
			ii x = ((i & 1) ?  ii(j, 0) : ii(0, j));
			seg::update(i, x);
		}
		else {
			int l, r; cin >> l >> r; l--, r--;
			ii res = seg::query(l, r);
			if (l & 1)
				cout << res.f - res.s << endl;
			else
				cout << res.s - res.f << endl;
		}
	}

    return(0);
}
