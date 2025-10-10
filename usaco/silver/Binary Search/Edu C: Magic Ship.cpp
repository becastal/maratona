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

map<char, pair<int, int>> mov = {
	{'U', {0, +1}},
	{'D', {0, -1}},
	{'R', {+1, 0}},
	{'L', {-1, 0}},
};

int solve() {
	int x1, y1; cin >> x1 >> y1;
	int x2, y2; cin >> x2 >> y2;

	int n; cin >> n;
	string s; cin >> s;

	ll dx = 0, dy = 0;
	for (char c : s) tie(dx, dy) = pair<int, int>(dx + mov[c].f, dy + mov[c].s);

	auto pos = [&](ll m) {
		ll q = m / n, r = m % n;
		ll x_ = x1 + q * dx, y_ = y1 + q * dy;

		for (int i = 0; i < r; i++) {
			char c = s[i];
			tie(x_, y_) = pair<ll, ll>(x_ + mov[c].f, y_ + mov[c].s);
		}

		return pair<ll, ll>(x_, y_);
	};

	auto da = [&](ll m) {
		auto [x_, y_] = pos(m);
		return (abs(x_ - x2) + abs(y_ - y2) <= m);
	};

	ll l = 0, r = (ll)1e16, res = -1;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;
			res = m;
		} else {
			l = m+1;
		}
	}

	cout << res << endl;
	//cout << (pos(res) == pair<ll, ll>(x2, y2) ? res : -1LL) << endl;

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
