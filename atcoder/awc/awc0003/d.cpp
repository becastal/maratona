#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, m; cin >> n >> k >> m;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<int> P(n+1);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] + A[i-1];
	}

	int res = 0;
	for (int l = 0, r = 0; l <= n; l++) {
		r = max(r, l);
		while (r <= n and (r - l < k or P[r] - P[l] < m)) {
			r++;
		}
		//printf("%lld, %lld\n", l, r);

		if (r <= n) {
			res += n - r + 1;
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

