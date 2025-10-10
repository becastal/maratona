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
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	ll res = 0;
	for (int i = 0; i < m; i++) {
		vector<ll> b;
		
		for (int j = 0; j < n; j++) {
			b.push_back(a[j][i]);
		}
		ll s = accumulate(b.begin(), b.end(), 0LL);

		ll agr = 0;
		sort(b.begin(), b.end());
		for (int j = 0; j < n; j++) {
			agr += b[j];
			res += llabs((s - agr) - (n - 1 - j) * b[j]);
		}
	}
	cout << res << endl;

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
