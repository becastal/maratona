#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	map<int, vector<int>> O;

	vector<int> P(n+1, 0);
	O[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] ^ A[i-1];
		O[P[i]].push_back(i);
	}

	while (q--) {
		int l, r, ok = 0; cin >> l >> r;

		// k = 2;
		ok |= (P[l-1] == P[r]);

		// k = 3;
		auto it = lower_bound(all(O[P[l-1]]), r);
		int b = (it == O[P[l-1]].begin() ? INT_MIN : *prev(it));

		auto it_ = upper_bound(all(O[P[r]]), l-1);
		int a = (it_ == O[P[r]].end() ? INT_MAX : *it_);
	
		//printf("P[l-1] = %d, P[r] = %d\n(%d, %d)\n", P[l-1], P[r], a, b);

		ok |= (a <= b);
		cout << (ok ? "YES" : "NO") << endl;
	}
	cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

