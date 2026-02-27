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

	vector<array<int, 2>> E(m);
	set<int> S;
	for (int i = 1; i <= n; i++) {
		S.insert(i);
	}

	for (auto& [b, a] : E) {
		cin >> a >> b;
	}

	sort(all(E));
	for (auto [b, a] : E) {
		auto it = S.lower_bound(a);	
		if (it == S.end() or *it > b) return cout << "No" << endl, 0;
		S.erase(*it);
	}
	cout << "Yes" << endl;


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

