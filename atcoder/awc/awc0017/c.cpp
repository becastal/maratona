#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<int> C(n);
	for (int& i : C) {
		cin >> i;
	}

	vector<int> A(n - 1);
	for (int i = 0; i < n-1; i++) {
		A[i] = C[i] == C[i+1];
	}

	vector<int> P(n);
	for (int i = 1; i < n; i++) {
		P[i] = P[i-1] + A[i-1];
	}

	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		cout << P[r] - P[l] << endl;
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

