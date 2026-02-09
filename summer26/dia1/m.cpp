#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n; cin >> n;
	vector<int> A(n);

	for (int& i : A) {
		cin >> i;
	}

	map<int, int> M, R;
	for (int i = 0; i < n; i++) {
		map<int, int> M_;

		for (auto [g, t] : M) {
			int g_ = gcd(g, A[i]);
			M_[g_] += t;
		}
		M_[A[i]]++;

		for (auto [a, b] : M_) {
			R[a] += b;
		}
		M = move(M_);
	}

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << R[x] << endl;
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
