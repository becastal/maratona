#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, v; cin >> n >> v;
	vector<int> D(n), T(n);

	for (int i = 0; i < n-1; i++) {
		cin >> D[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> T[i];
	}

	int foi = 0;
	for (int i = 1, p = 0; i < n; i++) {
		p += D[i-1];
		if (p < __int128_t(1) * T[i] * v) {
			foi = 1;
			cout << (i + 1) << " ";
		}
	}
	if (!foi) cout << -1;
	cout << endl;

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

