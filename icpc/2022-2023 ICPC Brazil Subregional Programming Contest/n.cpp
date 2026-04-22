#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

// BIT
//
// BIT de soma 0-based
// 
// upper_bound(x) retorna o menor p tal que pref(p) > x 
//
// Complexidades:
// build - O(n)
// update - O(log(n))
// query - O(log(n))
// upper_bound - O(log(n))

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
	int n; cin >> n;
	vector<int> A(n), B(n);
	for (int& i : A) {
		cin >> i;
	}
	for (int& i : B) {
		cin >> i;
	}
	int k, l; cin >> k >> l;

	Bit bit_s(n), bit_c(n);
	vector<int> O(n);
	iota(all(O), 0);
	sort(all(O), [&](int a, int b) { 
		return B[a] > B[b];
	});
	vector<int> P(n);
	for (int i = 0; i < n; i++) {
		P[O[i]] = i;
	}

	int res = LLONG_MIN, s = 0;
	auto add = [&](int p) {
		//cout << "+ " << A[p] << ", " << B[p] << endl;;
		s += A[p];
		int pb = P[p];
		bit_c.update(pb, +1);
		bit_s.update(pb, +B[p]);
	};

	auto rem = [&](int p) {
		//cout << "- " << A[p] << ", " << B[p] << endl;;
		s -= A[p];
		int pb = P[p];
		bit_c.update(pb, -1);
		bit_s.update(pb, -B[p]);
	};

	auto calc = [&]() {
		int ub = bit_c.upper_bound(l);
		res = max(res, s + bit_s.pref(ub - 1));
		//cout << s << ", " << bit_s.pref(ub - 1) << endl;
	};

	for (int i = 0; i < k; i++) {
		add(i);	
	}

	calc();
	for (int i = 0; i < k; i++) {
		rem(k - 1 - i);
		add(n - 1 - i);
		calc();
	}
	cout << res << endl;

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

