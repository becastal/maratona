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
	vector<int> W(n), C(m);

	for (int& i : W) {
		cin >> i;
	}
	for (int& i : C) {
		cin >> i;
	}
	sort(rall(W)), sort(rall(C));

	if (W[0] > C[0] or accumulate(all(W), 0LL) > accumulate(all(C), 0LL)) return cout << "No" << endl, 0;

	vector<int> P(m);
	function<int(int)> dfs = [&](int p) {
		if (p == n) return 1;

		unordered_set<int> foi;
		for (int j = 0; j < m; j++) {
			if (P[j] + W[p] > C[j]) continue;

			int sobra = C[j] - P[j];
			if (foi.count(sobra)) continue;
			foi.insert(sobra);

			P[j] += W[p];
			if (dfs(p + 1)) return 1;
			P[j] -= W[p];
		}

		return 0;
	};
	
	cout << (dfs(0) ? "Yes" : "No") << endl;
	

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

