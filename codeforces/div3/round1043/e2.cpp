#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1);
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--)
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

const int MAX = 4e5+10;
const int tam = ceil(sqrt(MAX));

int solve() {
	int n, m, q; cin >> n >> m >> q;
	// A crescente e B decrescente. dai uma query xi, yi, zi eh 
	// soma dos zi maiores valores entre os xi ultimos valores de A e os yi primeiros valores de B
	// sei fazer com mo + Bit mas talvez devagar demais
	// tem que comprimir coordenada pra Bit

	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
	sort(all(A)), sort(rall(B));

	vector<int> C(n+m);
	for (int i = 0; i < n+m; i++) {
		C[i] = i < n ? A[i] : B[i - n];
	}

	vector<array<int, 4>> Q(q); // l, r, k, id
	for (int i = 0, xi, yi, zi; i < q; i++) {
		cin >> xi >> yi >> zi;
		Q[i] = {n - xi, n + yi - 1, zi, i};
	}

	sort(all(Q), [&](auto a, auto b) {
		if (a[0] / tam != b[0] / tam) return a[0] < b[0];
		if ((a[0] / tam) % 2) return a[1] > b[1];
		return a[1] < b[1];	
	});

	vector<int> D(C);
	sort(all(D));
	D.erase(unique(all(D)), D.end());
	for (int& i : C) i = lower_bound(all(D), i) - D.begin();
	int nn = D.size();

	Bit bit_cont(nn), bit_soma(nn);
	auto add = [&](int i) {
		bit_cont.update(C[i], +1);
		bit_soma.update(C[i], +D[C[i]]);
	};
	auto rem = [&](int i) {
		bit_cont.update(C[i], -1);
		bit_soma.update(C[i], -D[C[i]]);
	};

	auto calc = [&](int k) -> ll {
		if (k <= 0) return 0LL;
		ll total_cont = bit_cont.pref(nn - 1);
		ll total_soma = bit_soma.pref(nn - 1);
		if (k >= total_cont) return total_soma;

		ll x = total_cont - k;
		ll p = bit_cont.upper_bound(x);

		ll antes_cont = bit_cont.pref(p - 1);
		ll antes_soma  = bit_soma.pref(p - 1);
		if (p < nn && x - antes_cont > 0) {
			antes_soma += (x - antes_cont) * D[p];
		}
		return total_soma - antes_soma;
	};

	int l = 0, r = -1;	
	vector<ll> R(q);
	for (auto [ql, qr, k, id] : Q) {
		//cout << ql << ' ' << qr << endl;
		while (r < qr) add(++r);
		while (l > ql) add(--l);
		while (l < ql) rem(l++);
		while (r > qr) rem(r--);
		R[id] = calc(k);
	}
	for (ll i : R) cout << i << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

