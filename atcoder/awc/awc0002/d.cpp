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
	set<int> C;

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		C.insert(x);
	}

	int res = 0;
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		auto it = C.upper_bound(x);

		if (it != C.begin()) {
			it = prev(it);
			if (x < *it) continue;
			res++;
			C.erase(*it);
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

