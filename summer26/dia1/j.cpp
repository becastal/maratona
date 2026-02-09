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
	vector<ll> F;

	Bit(int n_) : n(n_), F(n_+1, 0) {}
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) {
			F[i] += x;
		}
	}
	ll pref(int i) {
		ll res = 0;
		for (i++; i; i-=i&-i) {
			res += F[i];	
		}
		return res;
	}
};

signed solve(int n, int m) {
	vector<int> P(n), P_(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> P[i]; 
		P_[P[i]] = i;
	}

	ll res = 0;
	Bit bit(n+1);
	for (int i = n-1; i >= 0; i--) {
		res += bit.pref(P[i]);
		bit.update(P[i], +1);
	}

	const int tam = ceil(sqrt(n));
	int nn = (n + tam - 1) / tam;

	vector<vector<int>> B(nn);
	for (int i = 0; i < nn; i++) {
		for (int j = i * tam; j < min(n, (i + 1) * tam); j++) {
			B[i].push_back(P[j]);
		}
		sort(all(B[i]));
	}

	auto query = [&](int l, int r, int x, int tp) {
		if (l > r) return 0LL;
		int l_ = l / tam, r_ = r / tam;
		ll res = 0;

		if (l_ == r_) {
			for (int i = l; i <= r; i++) if (P[i]) {
				res += (tp ? P[i] < x : P[i] > x);
			}
		} else {
			for (int i = l, lim = (l_ + 1) * tam - 1; i <= lim; i++) if (P[i]) {
				res += (tp ? P[i] < x : P[i] > x);
			}

			for (int i = l_ + 1; i <= r_ - 1; i++) {
				if (tp) {
					res += lower_bound(all(B[i]), x) - B[i].begin();
				} else {
					res += B[i].end() - upper_bound(all(B[i]), x);
				}
			}

			for (int i = r_ * tam; i <= r; i++) if (P[i]) {
				res += (tp ? P[i] < x : P[i] > x);
			}
		}

		return res;
	};

	while (m--) {
		int x; cin >> x;
		int p = P_[x];

		cout << res << endl;
		res -= query(0, p, x, 0);
		res -= query(p, n-1, x, 1);

		int bl = p / tam;
		B[bl].erase(lower_bound(all(B[bl]), x));
		P[p] = 0;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1, n, m; //cin >> t;
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}
