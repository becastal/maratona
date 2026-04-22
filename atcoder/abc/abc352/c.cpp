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

	vector<int> A(n), B(n);
	int soma_a = 0;

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		soma_a += A[i];
	}

	int res = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, soma_a - A[i] + B[i]);
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

