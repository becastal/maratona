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
	vector<int> A(n), B;
	for (int& i : A) {
		cin >> i;
	}
	int mx = *max_element(all(A));

	for (int& i : A) {
		while ((i << 1) <= mx) {
			i <<= 1;
		}
		B.push_back(i);
	}
	sort(all(B));

	int res = mx - B[0];
	for (int i = 0; i < n-1; i++) {
		res = min(res, 2 * B[i] - B[i + 1]);
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

