#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(m), B(m);
	for (int i = 0, nn; i < m; i++) {
		cin >> nn;
		for (int j = 0, a; j < nn; j++) {
			cin >> a; a--;
			A[i] |= (1 << a);
		}
		char c; cin >> c;
		B[i] = c == 'o';
	}

	int res = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		int ok = 1;
		for (int i = 0; i < m and ok; i++) { 
			if (B[i]) {
				ok &= __builtin_popcountll(mask & A[i]) >= k;
			} else {
				ok &= __builtin_popcountll(mask & A[i]) < k;
			}
		}
		res += ok;
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

