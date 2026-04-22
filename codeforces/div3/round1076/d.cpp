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
	for (int& i : A) {
		cin >> i;
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		if (i) {
			B[i] += B[i-1];
		}
	}
	
	int res = LLONG_MIN;
	sort(rall(A));
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n and (i + 1) >= B[j]) {
			j++;
		}
		res = max(res, A[i] * j);
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

