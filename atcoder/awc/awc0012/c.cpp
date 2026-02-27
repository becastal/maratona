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

	vector<vector<int>> A(2);
	for (int i = 0, h, p; i < n; i++) {
		cin >> h >> p;
		A[h].push_back(p);
	}
	sort(rall(A[0]));
	sort(rall(A[1]));

	if (A[0].size() < (k - m) or A[1].size() < m) return cout << -1 << endl, 0;
	cout << accumulate(A[0].begin(), A[0].begin() + (k - m), 0LL) + accumulate(A[1].begin(), A[1].begin() + m, 0LL) << endl;

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

