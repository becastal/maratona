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
	int n; cin >> n;
	vector<pair<int, int>> v(n);

	map<int, ll> a, b, c, d;
	for (auto& [x, y] : v) {
		cin >> x >> y;
		a[x]++;
		b[y]++;
		c[x+y]++;
		d[x-y]++;
	}

	ll res = 0;

	for (auto [i, j] : a) {
		res += j * (j-1);
	}
	for (auto [i, j] : b) {
		res += j * (j-1);
	}
	for (auto [i, j] : c) {
		res += j * (j-1);
	}
	for (auto [i, j] : d) {
		res += j * (j-1);
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
