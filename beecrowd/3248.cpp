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
	void update(int i, ll v) {
		for (++i; i <= n; i += i&-i) F[i] += v;
	}
	ll pref(int i) {
		ll res = 0;
		for (++i; i; i -= i&-i) res += F[i];
		return res;
	}
	ll query(int l, int r) {
		if (l > r) return 0;
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n; cin >> n;
	vector<int> A(n);

	Bit bit_suf(n+1), bit_pre(n+1);
	for (int& i : A) {
		cin >> i;
		bit_suf.update(i, +1);
	}


	ll res = 0;
	for (int i : A) {
		res += bit_pre.query(i + 1, n) * bit_suf.pref(i - 1);	
		bit_suf.update(i, -1);
		bit_pre.update(i, +1);
	}
	cout << res << endl;

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

