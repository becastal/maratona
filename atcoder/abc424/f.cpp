#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
tentar colocar (a, b) so nao da se:
	tem um (c, d) tal que:
	a < c < b < d ou c < a < d < c

basicamente e problema de quantos segmentos
eu so toco mas tem que ser online. parece
ser so segtree

pro caso 1: a < c < b < d:
	- pra todo segmento que comece em (a, b) exclusive
	eu marco o max possivel ending dele com point update.
	- dai pra um segmento novo (a, b), basta que a query
	em max (a, b) menor que b.

pro caso 2: c < a < d < c:
	- mesma ideia mas marco o final e a query eh de min.
*/

struct Seg {
	int n, e;
	vector<int> seg, v;
	function<int(int, int)> f;

	Seg(int n_, vector<int>& v_, function<int(int, int)> f_, int e_) :
		n(n_), seg(4 * n), v(v_), f(f_), e(e_) {
		build(1, 0, n-1);
	}

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = v[l];
		int m = (l + r) / 2;
		return seg[p] = f(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int query(int a, int b, int p, int l, int r) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return e;
		int m = (l + r) / 2;
		return f(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int query(int a, int b) { return query(a, b, 1, 0, n-1); }
	int update(int i, int x, int p, int l, int r) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l + r) / 2;
		return seg[p] = f(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
	int update(int i, int x) { return update(i, x, 1, 0, n-1); }
};

int solve() {
	int n, q; cin >> n >> q;

	vector<int> mn(n, INT_MIN), mx(n, INT_MAX);
	Seg SA(n, mn, [](int a, int b) -> int { return max(a, b); }, INT_MIN);
	Seg SB(n, mx, [](int a, int b) -> int { return min(a, b); }, INT_MAX);

	for (int i = 0, a, b; i < q; i++) {
		cin >> a >> b; a--, b--;
		if (a > b) swap(a, b);

		int ruim = 0;
		if (b - a <= 1) ruim = 0;
		else {
			ruim = (SA.query(a+1, b-1) > b) or (SB.query(a+1, b-1) < a);
		}

		if (!ruim) {
			if (SA.query(a, a) < b) SA.update(a, b);
			if (SB.query(b, b) > a) SB.update(b, a);
		}
		cout << (!ruim ? "Yes" : "No") << endl;
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

