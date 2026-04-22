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

	Bit(int n_) : n(n_), A(n + 1) {}
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
		return pref(r) - pref(l - 1);
	}
};

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);
	vector<vector<int>> B(n + 1);
	vector<int> P(n + 2);

	for (auto& [l, r] : A) {
		cin >> l >> r;
		B[l].push_back(r);
		P[l]++, P[r + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		P[i] += P[i-1];
	}

	Bit bit(n + 1);
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int r : B[i]) {
			bit.update(r, +1);
		}

		int l = i, r = n-i;
		if (r < l) continue;
		int esq = P[l], dir = P[r];
		int osdois = bit.query(r, n);
		esq -= osdois, dir -= osdois;

		cout << "~~~~~~~~~~~~~~~~~~" << endl;
		cout << "l: " << l << endl;
		cout << "r: " << r << endl;
		cout << "esq: " << esq << endl;
		cout << "dir: " << dir << endl;
		cout << "osdois: " << osdois << endl;
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

