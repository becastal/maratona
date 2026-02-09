#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);

	for (int& i : A) cin >> i;

	int i = 0;
	for (; i < n;) {
		int mx = i;

		for (int j = i; j <= mx; j++) {
			mx = max(mx, min(n-1, j + A[j] - 1));
		}
		
		if (i == mx) break;
		i = min(mx, n);
	}
	cout << min(n, i + 1) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

