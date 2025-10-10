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

	Bit(int n_) : n(n_), F(n_+1, 0) {};
	void update(int i, ll v) {
		for (++i; i <= n; i+=i&-i) F[i] += v;
	}
	ll pref(int i) {
		if (i < 0) return 0;
		ll res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	ll query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);

	vector<ll> X, Y;
	for (auto& [a, b] : A) {
		cin >> a >> b;
		X.push_back(a);
		Y.push_back(b);
	}

	sort(all(X)), sort(all(Y));
	X.erase(unique(all(X)), X.end());
	Y.erase(unique(all(Y)), Y.end());
	int x = (int)X.size(), y = (int)Y.size();

	Bit xbit_c(x), xbit_s(x);
	Bit ybit_c(y), ybit_s(y);

	__int128 res = 0;
	for (auto& [a, b] : A) {
		a = lower_bound(all(X), a) - X.begin();
		ll amenorc = xbit_c.pref(a-1), amenors = xbit_s.pref(a-1);
		ll amaiorc = xbit_c.query(a+1, x-1), amaiors = xbit_s.query(a+1, x-1);
		
		res += (X[a] * amenorc - amenors) + (amaiors - amaiorc * X[a]);

		b = lower_bound(all(Y), b) - Y.begin();
		ll bmenorc = ybit_c.pref(b-1), bmenors = ybit_s.pref(b-1);
		ll bmaiorc = ybit_c.query(b+1, y-1), bmaiors = ybit_s.query(b+1, y-1);

		res += (Y[b] * bmenorc - bmenors) + (bmaiors - bmaiorc * Y[b]);

		xbit_c.update(a, +1);
		xbit_s.update(a, +X[a]);
		ybit_c.update(b, +1);
		ybit_s.update(b, +Y[b]);
	}

	if (!res) return cout << 0 << endl, 0;
	string R = "";
	while (res) {
		R.push_back('0' + (res % 10));
		res /= 10;
	}
	reverse(all(R));
	cout << R << endl;

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

