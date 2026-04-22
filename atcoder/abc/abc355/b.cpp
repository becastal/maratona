#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<array<int, 2>> A(n + m);
	for (int i = 0; i < n + m; i++) {
		cin >> A[i][0];
		A[i][1] = (i < n);
	}
	sort(all(A));
	for (int i = 1; i < n + m; i++) {
		if (A[i][1] and A[i-1][1]) return cout << "Yes" << endl, 0;
	}
	cout << "No" << endl;

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

