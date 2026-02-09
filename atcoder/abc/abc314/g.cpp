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

int solve() {
	ll n, m, h; cin >> n >> m >> h;

	vector<ll> S(m), Comp = {0};
	vector<ll> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i]; B[i]--;
		Comp.push_back(S[B[i]] += A[i]);
	}

	sort(all(Comp));
	Comp.erase(unique(all(Comp)), Comp.end());
	int nn = Comp.size();

	Bit Bc(nn), Bs(nn);
	auto add = [&](ll x) {
		int p = lower_bound(all(Comp), x) - Comp.begin();
		Bc.update(p, +1);
		Bs.update(p, +x);
	};
	auto rem = [&](ll x) {
		int p = lower_bound(all(Comp), x) - Comp.begin();
		Bc.update(p, -1);
		Bs.update(p, -x);
	};
	auto query = [&](int kk) -> ll {
		ll tc = Bc.pref(nn - 1), ts = Bs.pref(nn - 1);

		if (kk <= 0) return 0LL;
		if (kk >= tc) return ts;

		ll k = tc - kk;
		int p = Bc.upper_bound(k - 1);

		ll cantes = Bc.pref(p - 1);
		ll santes = Bs.pref(p - 1);

		ll quero = k - cantes;
		ll menores = santes + quero * 1LL * Comp[p];

		return ts - menores;
	};
	for (int i = 0; i < m; i++) {
		add(0);
	}

	fill(all(S), 0);
	ll pref = 0;
	vector<int> R(m + 1);
	for (int k = 0, i = -1; k <= m; k++) { 
		while (i + 1 < n) {
			rem(S[B[i + 1]]);
			add(S[B[i + 1]] += A[i + 1]);
			pref += A[i + 1];

			if (pref - query(k) < h) {
				i++;
				continue;
			}

			pref -= A[i + 1];
			rem(S[B[i + 1]]);
			add(S[B[i + 1]] -= A[i + 1]);
			break;
		}


		R[k] = i + 1;
	}

	for (int i = 0; i <= m; i++) {
		cout << R[i] << " \n"[i==m];
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

