#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

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

	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<int> B(A);
	sort(all(B));
	B.erase(unique(all(B)), B.end());
	for (int& i : A) i = lower_bound(all(B), i) - B.begin();
	int m = B.size();

	ordered_multiset<int> O; 

	Bit bit_c(m), bit_s(m);

	auto add = [&](int i) {
		O.insert({A[i], i});
		bit_c.update(A[i], +1);
		bit_s.update(A[i], +B[A[i]]);
	};
	auto rem = [&](int i) {
		O.erase({A[i], i});
		bit_c.update(A[i], -1);
		bit_s.update(A[i], -B[A[i]]);
	};
	auto calc = [&]() -> long long {
		int mi = O.find_by_order((k - 1) / 2)->first;
		ll med = B[mi];

		ll menores_c = bit_c.pref(mi - 1);
		ll menores_s = bit_s.pref(mi - 1);
		ll res = menores_c * med - menores_s;

		ll maiores_c = bit_c.query(mi + 1, m - 1);
		ll maiores_s = bit_s.query(mi + 1, m - 1);
		res += maiores_s - med * maiores_c;

		return res;
	};

	for (int i = 0; i < k; i++) {
		add(i);
	}

	vector<ll> R = {calc()};
	for (int i = k; i < n; i++) {
		rem(i-k);
		add(i);
		R.push_back(calc());
	}

	for (ll i : R) cout << i << ' '; cout << endl;

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

