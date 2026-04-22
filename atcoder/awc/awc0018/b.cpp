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
	vector<int> C(m);
	for (int& i : C) {
		cin >> i;
	}

	int res = 0;
	for (int i = 0, k; i < n; i++) {
		cin >> k;
		vector<int> P(k);
		map<int, int> C_;
		for (int& j : P) {
			cin >> j; j--;
			C_[j]++;
		}

		for (auto [a, b] : C_) if (b <= C[a]) {
			res += b;
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

