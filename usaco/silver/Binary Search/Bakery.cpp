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
	ll n, tc, tm; cin >> n >> tc >> tm;
	vector<tuple<ll, ll, ll>> A(n);
	for (auto& [a, b, c] : A) {
		cin >> a >> b >> c;
	}


	auto teto = [](ll a, ll b) {
		return (a + b - 1) / b;
	};
	auto chao = [](ll a, ll b) {
		return a / b - (a < 0 and a % b);
	};

	auto da = [&](ll k) {
		ll L = max(0LL, k - (tm - 1));
		ll R = min(k, tc - 1);

		vector<pair<ll, int>> ev;
		auto push = [&](ll l, ll r) {
			ev.emplace_back(max(L, l), 0);
			ev.emplace_back(min(R, r), 1);
		};

		push(0, k);
		for (auto& [a, b, c] : A) {
			if (a == b) {
				if (a * (tc + tm - k) > c) return 0;
				push(0, k);
			} else if (b > a) {
				push(0, chao((c - a * tc - b * tm + b * k), (b - a)));
			} else {
				push(teto(a * tc + b * tm - b * k - c, a - b), k);
			}
		}

		sort(ev.begin(), ev.end());
		int agr = 0;
		for (auto [x, tp] : ev) { 
			agr += tp ? -1 : +1;
			if (agr == n + 1) return 1;
		}
		
		return 0;
	};

	ll l = 0, r = tc + tm - 2, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
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
