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
	ll n, m; cin >> n >> m;

	vector<ll> c(n), w(n);

	for (ll& i : c) cin >> i;
	for (ll& i : w) cin >> i;

	priority_queue<pair<ll, int>> pq;
	vector<int> foi(n, 0);
	ll tot = 0;

	for (int i = 0; i < n; i++) {
		m -= c[i] % 100;

		if (c[i] % 100 > 0) {
			pq.emplace(-((100 - (c[i] % 100)) * w[i]), i);
		} 

		while (m < 0) {
			auto [wj, j] = pq.top(); pq.pop();
			wj = -wj;

			foi[j] = 1;
			tot += wj;
			m += 100;
		}
	}

	cout << tot << endl;
	for (int i = 0; i < n; i++) {
		if (c[i] % 100 == 0) {
			cout << c[i] / 100 << ' ' << 0 << endl;
		} else if (foi[i]) {
			cout << c[i] / 100 + 1 << ' ' << 0 << endl;
		} else {
			cout << c[i] / 100 << ' ' << c[i] % 100 << endl;
		}
	}

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
