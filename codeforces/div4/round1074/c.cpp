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
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	sort(all(A));
	A.erase(unique(all(A)), A.end());

	int res = 0;
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		while (r < n and A[r] - A[l] == r - l) {
			r++;
		}
		res = max(res, r - l);
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


