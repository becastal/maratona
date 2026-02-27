#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, t; cin >> n >> t;
	vector<int> H(n), C(n);
	for (int& i : H) {
		cin >> i;
	}
	for (int& i : C) {
		cin >> i;
	}

	int res = 0;
	for (int i = 0; i < n; i++) if (H[i] <= t) {
		res += C[i];
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

