#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		A[i] *= -1;

		int m; cin >> m;
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			A[i] += x;
		}
	}

	int res = 0;
	sort(rall(A));
	for (int i = 0; i < k and A[i] > 0; i++) {
		res += A[i];
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

