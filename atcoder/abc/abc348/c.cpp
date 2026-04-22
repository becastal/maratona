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

	map<int, int> A;
	for (int i = 0, a, c; i < n; i++) {
		cin >> a >> c;
		if (A.count(c)) {
			A[c] = min(A[c], a);
		} else {
			A[c] = a;
		}
	}

	int res = LLONG_MIN;
	for (auto [a, b] : A) {
		res = max(res, b);
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

