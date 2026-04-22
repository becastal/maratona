#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

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

int solve() {
	int n, k; cin >> n >> k;
	vector<int> P(n);
	for (int& i : P) {
		cin >> i;
		i--;
	}

	Bit bita(n);
	int resa = 0;
	for (int r = 0, l = 0, inv = 0; r < n; r++) {
		int tam = r - l;
		inv += tam - bita.pref(P[r]);
		bita.update(P[r], +1);

		while (inv > k) {
			inv -= bita.pref(P[l] - 1);	
			bita.update(P[l++], -1);
		}

		resa += (r - l + 1);
	}
	
	int resb = 0;
	if (k == 0) {
		resb = 0;
	} else {
		Bit bitb(n);
		for (int r = 0, l = 0, inv = 0; r < n; r++) {
			int tam = r - l;
			inv += tam - bitb.pref(P[r]);
			bitb.update(P[r], +1);

			while (inv > k - 1) {
				inv -= bitb.pref(P[l] - 1);	
				bitb.update(P[l++], -1);
			}

			resb += (r - l + 1);
		}
	}

	cout << resa - resb << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

