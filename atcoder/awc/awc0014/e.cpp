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
	vector<vector<int>> F;
	Bit(int n_) : n(n_), F(2, vector<int>(n+1)) {}

	void add(int b, int i, int x) {
		for (i++; i <= n; i+=i&-i) F[b][i] += x;
	}

	void update(int l, int r, int x) {
		add(0, l, x);
		add(0, r + 1, -x);
		add(1, l, x*l);
		add(1, r + 1, -x*(r+1));
	}

	int soma(int b, int i) {
		int res = 0;
		for (i++; i; i-=i&-i) res += F[b][i];
		return res;
	}

	int pref(int i) {
		return soma(0, i) * (i + 1) - soma(1, i);
	}

	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n, q; cin >> n >> q;

	Bit bit(n);
	for (int i = 0, c; i < n; i++) {
		cin >> c;
		bit.update(i, i, c);
	}

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int l, r, c; cin >> l >> r >> c; l--, r--;
			bit.update(l, r, c);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << bit.query(l, r) << endl;
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

