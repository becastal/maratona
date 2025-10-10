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

	vector<int> x(n), v(n);
	for (int& i : x) cin >> i;
	for (int& i : v) cin >> i;

	auto da = [&](double t) {
		vector<pair<double, int>> ev;

		for (int i = 0; i < n; i++) {
			ev.emplace_back(x[i] - v[i] * t, 0);
			ev.emplace_back(x[i] + v[i] * t, 1);
		}
		sort(ev.begin(), ev.end());

		int agr = 0;
		for (auto [pos, tp] : ev) {
			agr += (tp ? -1 : +1);
			if (agr == n) return 1;
		}
		return 0;
	};

	double l = 0, r = 1e9;
	for (int i = 0; i < 100; i++) {
		double m = (l + r) / 2.0;

		if (da(m)) {
			r = m;
		} else {
			l = m;
		}
	}

	cout << fixed << setprecision(12);
	cout << l << endl;

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
