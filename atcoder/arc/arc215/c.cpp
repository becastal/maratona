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
	vector<array<int, 3>> A(n);

	vector<vector<array<int, 2>>> X(n + 1);
	for (int i = 0; i < n; i++) {
		auto& [x, y, z] = A[i];
		cin >> x >> y >> z;
		X[x].push_back({y, z});
	}
	
	sort(all(A), [&](auto& a, auto& b) {
		return a[0] > b[0];
	});

	int res = 0;
	set<int> Y, Z;
	vector<array<int, 2>> ruins;
	for (int x = n; x >= 1; x--) {
		int bom = 0;
		for (auto [y, z] : X[x]) {
			bom |= Y.empty() or *Y.begin() <= y or Z.empty() or *Z.begin() <= z;
		}

		if (bom) {
			for (auto [y, z] : X[x]) {
				Y.insert(y);
				Z.insert(z);
				res++;
			}
			for (auto [y, z] : ruins) {
				Y.insert(y);
				Z.insert(z);
				res++;
			}
			ruins.clear();
		} else {
			for (auto [y, z] : X[x]) {
				ruins.push_back({y, z});
			}
		}
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

