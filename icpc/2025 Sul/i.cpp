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
	int q; cin >> q;

	vector<int> V;
	vector<tuple<char, int, int>> Q(q);
	for (auto& [tp, a, b] : Q) {
		cin >> tp;

		if (tp == 'I') {
			cin >> a; b = -1;
			V.push_back(a);
		} else {
			cin >> a >> b;
		}
	}

	vector<int> V_(V);
	sort(all(V_));
	V_.erase(unique(all(V_)), V_.end());
	auto id = [&](int x) { return lower_bound(all(V_), x) - V_.begin(); };

	int n = (int)V_.size();
	Bit A(n+1), B(n+1);

	auto calc = [&](int x) {
		int p = A.upper_bound(x-1);
		ll c0 = p-1 >= 0 ? A.pref(p-1) : 0;
		ll s0 = p-1 >= 0 ? B.pref(p-1) : 0;
		if (x - c0 > 0 and p < n) s0 += (x - c0) * V_[p];
		return s0;
	};

	for (auto [tp, a, b] : Q) {
		if (tp == 'I') {
			int a_ = id(a);
			A.update(a_, +1);
			B.update(a_, +a);
		} else {
			int cont = A.pref(n-1);
			ll s = B.pref(n-1);

			auto f = [&](int x) {
				return s - calc(cont - x);
			};
			cout << f(b) - f(a-1) << endl;
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
