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
	for (auto& i : v) for (auto& j : i) cin >> j;

	sort(v.begin(), v.end(), [&](vector<int>& a, vector<int>& b) {
		ll Sa = accumulate(a.begin(), a.end(), 0LL), Sb = accumulate(b.begin(), b.end(), 0LL);

		if (Sa == Sb) {
			ll sa = 0, sb = 0;
			for (int i = 0, agr = n*m; i < m; i++) {
				sa += (ll)(agr--)*a[i];
			}
			for (int i = 0, agr = n*m; i < m; i++) {
				sb += (ll)(agr--)*b[i];
			}

			return sa > sb;
		}

		return Sa > Sb;	
	});

	ll res = 0;
	for (int i = 0, agr = n*m; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += v[i][j] * (ll)(agr--);
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
