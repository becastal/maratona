#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<int> C = {0, n};
	vector<array<int, 2>> A(m);

	for (auto& [l, r] : A) {
		cin >> l >> r;
		C.push_back(l - 1);
		C.push_back(r);
	}

	sort(all(C));
	C.erase(unique(all(C)), C.end());
	int nn = (int)C.size();
	vector<vector<int>> L(nn);

	for (auto& [l, r] : A) {
		l = lower_bound(all(C), l - 1) - C.begin();
		r = lower_bound(all(C), r) - C.begin();
		L[l].push_back(r);
	}

	int res = 0;
	for (int p = 0, i = 0; p < nn - 1; ) {
		int mx_r = LLONG_MIN;
		while (i <= p) {
			for (int r : L[i]) {
				mx_r = max(mx_r, r);
			}
			i++;
		}

		if (p >= mx_r) return cout << -1 << endl, 0;
		res++;
		p = mx_r;
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

