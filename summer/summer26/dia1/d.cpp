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
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res += F[i];	
		}
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

signed solve() {
	int n; cin >> n;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	
	int q; cin >> q;

	vector<vector<array<int, 2>>> Q(n);
	for (int i = 0, a, b; i < q; i++) {
		cin >> a >> b; a--, b--;
		Q[b].push_back({a, i});
	}

	map<int, int> M;

	vector<int> R(q);
	Bit bit(n);
	for (int i = 0; i < n; i++) {
		if (M.count(A[i])) {
			bit.update(M[A[i]], -1);
		}
		bit.update(M[A[i]] = i, +1);

		for (auto [l, id] : Q[i]) {
			R[id] = bit.query(l, i);
		}
	}

	for (int i : R) {
		cout << i << endl;
	}

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
