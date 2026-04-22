#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), P(n + 1);
	for (int& i : A) {
		cin >> i;
	}

	int res = 0;
	for (int i = 0, p = 0; i < n; i++) {
		p ^= P[i];
		if (A[i] ^ p) {
			p ^= 1;
			if (i+k > n) {
				return cout << -1 << endl, 0;
			}
			P[i+k] ^= 1;
			res++;
		}
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

