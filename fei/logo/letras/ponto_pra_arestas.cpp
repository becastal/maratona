#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n = 30, m = 22;
	vector<array<int, 2>> E;

	int u, v;
	while (cin >> u >> v) {
		E.push_back({u, v});
	}

	for (int i = 1; i < E.size(); i++) {
		auto [a, b] = E[i-1];
		auto [c, d] = E[i];

		cout << "(" << a * m + b << ", " << c * m + d << "), ";
	}
	cout << endl;

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

