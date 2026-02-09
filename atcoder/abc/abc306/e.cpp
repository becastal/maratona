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
	void update(int i, int v) {
		for (i++; i <= n; i+=i&-i) {
			F[i] += v;
		}
	}

	ll pref(int i) {
		ll res = 0;
		for (i++; i; i-=i&-i) {
			res += F[i];
		}
		return res;
	}

	ll query(int l, int r) {
		return pref(r) - pref(l-1);
	}

	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and F[p + (1<<i)] <= x)
				x -= F[p += (1 << i)];
		return p;
	}
};

int solve() {
	int n, k, q; cin >> n >> k >> q;

	vector<int> B = {0};
	vector<array<int, 2>> Q(q);
	for (auto& [a, b] : Q) {
		cin >> a >> b; a--;
		B.push_back(b);
	}

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	for (auto& [a, b] : Q) {
		b = lower_bound(all(B), b) - B.begin();
	}

	int m = (int)B.size();
	Bit bit(m);
	bit.update(0, n);
	ll res = 0;
	auto add = [&](int a) {
		if (bit.query(a, m-1) < k) {
			res += B[a];
			int b = bit.upper_bound(n-k-1);
			res -= B[b];
		}
		bit.update(a, +1);
	};
	auto rem = [&](int a) {
		if (bit.query(a, m-1) <= k) {
			res -= B[a];
			int b = bit.upper_bound(n-k-1);
			res += B[b];
		}
		bit.update(a, -1);
	};

	vector<int> A(n);
	for (auto [a, b] : Q) {
		rem(A[a]);
		add(A[a] = b);
		//for (int i = 0; i < m; i++) {
		//	cout << bit.query(i, i) << " \n"[i==m-1];
		//}

		cout << res << endl;
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

