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
	vector<string> a(n);
	for (auto& i : a) cin >> i;

	vector<vector<string>> b(m, vector<string>(n));
	vector<int> cont(n, 0);

	int res = 0;
	for (int i = 0; i < m; i++) {
		int agr = 0;
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
			cont[j] |= b[i][j] == a[j];
			agr += b[i][j] == a[j];
			res = max(res, agr);
		}
	}

	if (accumulate(cont.begin(), cont.end(), 0) != n) return cout << -1 << endl, 0;
	cout << n + 2 * (n - res) << endl;
	return 0;
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
