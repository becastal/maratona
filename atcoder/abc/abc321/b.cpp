#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, x; cin >> n >> x;
	vector<int> A(n - 1);
	for (int& i : A) {
		cin >> i;
	}

	int mn = *min_element(all(A)), mx = *max_element(all(A)), s = accumulate(all(A), 0LL), res = LLONG_MAX;
	for (int a = 0; a <= 100; a++) {
		if (a < mn) {
			int s_ = s - mx;
			if (s_ >= x) {
				res = min(res, a);
			}
		} else if (a > mx) {
			int s_ = s - mn;
			if (s_ >= x) {
				res = min(res, a);
			}
		} else {
			int s_ = s - mn - mx + a;
			if (s_ >= x) {
				res = min(res, a);
			}
		}
	}
	if (res == LLONG_MAX) res = -1;
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

