#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	vector<int> R(n);
	for (int& i : R) {
		cin >> i;
	}

	vector<int> A(n, LLONG_MAX);
	for (int i = 0, p = LLONG_MAX - 100; i < n; i++) {
		p = min(p + 1, R[i]);
		A[i] = min(A[i], p);
	}

	for (int i = n-1, p = LLONG_MAX - 100; i >= 0; i--) {
		p = min(p + 1, R[i]);
		A[i] = min(A[i], p);
	}


	int res = 0;
	for (int i = 0; i < n; i++) {
		res += max(0LL, R[i] - A[i]);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

