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
	vector<int> A;

	Bit (int n_) : n(n_), A(n + 1) {}
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) {
			A[i] += x;
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res += A[i];
		}
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l - 1);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i; i--;
	}

	vector<vector<array<int, 2>>> Q(n);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; r--, l--;
		Q[r].push_back({l, i});
	}

	Bit bit(n);
	vector<int> ult(n, -1), R(q);
	for (int i = 0; i < n; i++) {
		if (ult[A[i]] != -1) {
			bit.update(ult[A[i]], -1);
		}
		bit.update(ult[A[i]] = i, +1);

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

