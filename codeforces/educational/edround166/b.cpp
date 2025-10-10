#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n+1);

	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	ll res = 0, mndiff = LLONG_MAX;
	for (int i = 0, mn, mx; i < n; i++) {
		res += abs(A[i] - B[i]);

		tie(mn, mx) = minmax(A[i], B[i]);
		if (B[n] >= mn and B[n] <= mx) mndiff = 0;
		else mndiff = min({mndiff, llabs(mn - B[n]), llabs(mx - B[n])});
	}
	cout << res + mndiff + 1 << endl;

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

