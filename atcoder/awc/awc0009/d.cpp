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
	vector<array<int, 2>> E;
	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r;
		E.push_back({l, 0});
		E.push_back({r + 1, 1});
	}
	E.push_back({int(2e18), 0});

	sort(all(E));
	int bons = 0, agr = 0, ult  = 1;

	for (auto [p, tp] : E) {
		agr += (!tp ? +1 : -1);
		if (!tp and agr == 1) {
			bons += p - ult;

			if (bons >= n) {
				return cout << p - (bons - n + 1) << endl, 0;
			}
		}
		ult = p;
	}
	//assert(0);

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

