#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<ll> F;
	Bit(int n_) : n(n_), F(n_ + 1, 0) {};	

	void update(int i, int x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;
	};
	ll pref(int i) {
		ll res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	};
	ll query(int l, int r) {
		return pref(r) - pref(l-1);
	};
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<int> B(A);
	sort(all(B));
	B.erase(unique(all(B)), B.end());

	int m = (int)B.size();
	for (int& i : A) i = lower_bound(all(B), i) - B.begin();

	vector<array<int, 3>> Q(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; r--;
		Q[i] = {l, r, i};
	}

	int tam = ceil(sqrt(n));
	sort(all(Q), [&](auto& a, auto& b) {
		return make_pair(a[0] / tam, a[1]) < make_pair(b[0] / tam, b[1]);
	});

	ll res = 0;
	Bit bit(m+1);
	auto addl = [&](int id) {
		res += bit.pref(A[id]-1);
		bit.update(A[id], +1);
	};
	auto reml = [&](int id) {
		res -= bit.pref(A[id]-1);
		bit.update(A[id], -1);
	};
	auto addr = [&](int id) {
		res += bit.query(A[id]+1, m-1);
		bit.update(A[id], +1);
	};
	auto remr = [&](int id) {
		bit.update(A[id], -1);
		res -= bit.query(A[id]+1, m-1);
	};

	vector<ll> R(q);
	int agrl = 0, agrr = -1;
	for (auto [l, r, id] : Q) {
		while (agrl > l) addl(--agrl);	
		while (agrr < r) addr(++agrr);	
		while (agrl < l) reml(agrl++);
		while (agrr > r) remr(agrr--);
		R[id] = res;
	}
	for (ll i : R) cout << i << endl;

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

