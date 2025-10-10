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
	int n, m; cin >> n >> m;
	vector<vector<int>> l(n, vector<int>(110, 0)), r(m, vector<int>(110, 0)), a(n, vector<int>(m));
	vector<int> cont(110, 0);

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			l[i][a[i][j]]++;
			r[j][a[i][j]]++;
			cont[a[i][j]]++;
			mx = max(mx, a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (l[i][mx] + r[j][mx] - (a[i][j] == mx) == cont[mx]) return cout << mx-1 << endl, 0;
		}
	}
	cout << mx << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
