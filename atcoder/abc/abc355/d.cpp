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
		for (i++; i <= n; i += i&-i) {
			A[i] += x;
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i -= i&-i) {
			res += A[i];
		}
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n; cin >> n;

	vector<array<int, 2>> A(n);
	vector<int> B;

	for (int i = 0; i < n; i++) {
		auto& [l, r] = A[i];
		cin >> l >> r;
		B.push_back(l);
		B.push_back(r);
	}

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	for (auto& [l, r] : A) {
		l = lower_bound(all(B), l) - B.begin();
		r = lower_bound(all(B), r) - B.begin();
	}
	sort(all(A));

	int m = (int)B.size(), res = 0;
	Bit bit(m);

	for (auto [l, r] : A) {
		res += bit.query(l, m - 1);
		bit.update(r, +1);
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

