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
	int n; cin >> n;

	vector<pair<int, int>> a(n);
	map<int, int> X, Y;

	for (auto& [x, y] : a) {
		cin >> x >> y;
		X[x]++;
		Y[y]++;
	}

	if (n == 1) return cout << 1 << endl, 0;

	ll res = (ll)(X.rbegin()->f - X.begin()->f + 1) * (Y.rbegin()->f - Y.begin()->f + 1);
	for (auto [x, y] : a) {
		if (--X[x] == 0) X.erase(x);
		if (--Y[y] == 0) Y.erase(y);
		
		ll dx = X.rbegin()->f - X.begin()->f + 1;
		ll dy = Y.rbegin()->f - Y.begin()->f + 1;

		if (dx * dy == n-1) {
			res = min({res, (dx + 1) * dy, dx * (dy + 1)});
		} else res = min(res, dx * dy);

		X[x]++;
		Y[y]++;
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
