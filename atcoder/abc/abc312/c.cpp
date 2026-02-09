#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	sort(all(A));
	sort(all(B));

	int l = 0, r = (int)2e9, res = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		int ca = upper_bound(all(A), mid) - A.begin();
		int cb = m - (lower_bound(all(B), mid) - B.begin());

		if (ca < cb) {
			l = mid + 1;
		} else {
			r = mid - 1;
			res = mid;
		}
	}
	cout << res << endl;

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

