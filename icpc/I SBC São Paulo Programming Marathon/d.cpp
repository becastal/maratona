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

int solve() {
	int n, m, p, s; cin >> n >> m >> p >> s;

	vector<vector<int>> ruim(n+1, vector<int>(n+1, 0));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		ruim[u][v] = ruim[v][u] = 1;
	}

	int res = 0;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> a;
		int ps = 0, ss = 0;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				a.push_back(j + 1);
				if (j + 1 <= p) ps++;
				else if (j + 1 <= p + s) ss++;
			}
		}

		int ok = (ps == 1) and (ss == 1);
		for (int j = 0; j < (int)a.size(); j++) {
			for (int jj = j + 1; jj < (int)a.size(); jj++) {
				ok &= !ruim[a[j]][a[jj]];
			}
		}
		res += ok;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
