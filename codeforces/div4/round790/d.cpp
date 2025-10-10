#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));

	map<int, int> M, M_;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			M[i-j] += v[i][j];
			M_[i+j] += v[i][j];
		}
	}

	int res = 0;
	for (auto [a, b] : M) {
		for (auto [c, d] : M_) {
			if ((a + c) & 1) continue;
			int i = (a + c) / 2, j = c - i;

			if (i < 0 or i >= n or j < 0 or j >= m) continue;
			res = max(res, b + d - v[i][j]);
		}
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
