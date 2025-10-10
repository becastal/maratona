#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

// pqp eh isso + persistent pra nao foder as queries posteriores
const int MAX = 2e5+10;
namespace seg {
	struct nodo {
		ll soma, mx, mn;
		nodo() : soma(0), mx(0), mn(0) {};
		nodo(ll a) : soma(a), mx(a), mn(a) {};
		nodo(ll a, ll b, ll c) : soma(a), mx(b), mn(c) {};
		friend nodo operator +(nodo a, nodo b) { 
			return nodo(a.soma + b.soma, max(a.mx, b.mx), min(a.mn, b.mn));
		};
	};
	nodo seg[4*MAX];
	ll lazy[4*MAX];
	int n, *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (lazy[p] == -1) return;

		seg[p].soma = lazy[p] * (r - l + 1);
		seg[p].mx = seg[p].mn = lazy[p];
		if (l != r) lazy[2*p] = lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
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
		if (b < l or r < a or seg[p].mx < x) return seg[p];
		if (l == r) return seg[p] = nodo(seg[p].soma % x);

		if (a <= l and r <= b and seg[p].mx == seg[p].mn) {
			lazy[p] = seg[p].mx % x;
			prop(p, l, r);
			return seg[p];
		}
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<array<int, 4>> Q(q);
	int id_ = 0;
	for (auto& [x, l, r, id] : Q) {
		cin >> l >> r >> x; l--, r--;	
		id = id_++;
	}
	sort(rall(Q));

	seg::build(n, A.data());

	vector<ll> res(q);
	for (auto& [x, l, r, id] : Q) {
		seg::update(l, r, x);
		res[id] = seg::query(l, r).soma;
	}
	for (int i = 0; i < q; i++) {
		cout << res[i] << " \n"[i==q-1];
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

