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
	vector<int> F;

	Bit(int n_) : n(n_), F(n+1) { }
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

int solve() {
	int n, q; cin >> n >> q;

	Bit bit(n);
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		bit.update(i, A[i]);
	}

	while (q--) {
		int tp; cin >> tp;
		
		if (tp == 1) {
			int l, r; cin >> l >> r; l--, r--;
			cout << bit.query(l, r) << endl;
		} else {
			int i, x; cin >> i >> x; i--;
			bit.update(i, -A[i]);
			bit.update(i, A[i] = x);
		}
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

