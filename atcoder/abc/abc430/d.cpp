#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const ll INF = 2e12 + 10;

int solve() {
	int n; cin >> n;

	set<array<ll, 2>> S;
	S.insert({0, INF});

	ll res = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		ll rx = INF;

		auto it = S.lower_bound({x, -INF});

		if (it != S.begin()) {
			auto pl = prev(it);
			auto [a, ra] = *pl;

			if (ra != INF) res -= ra;
			ra = min(ra, x - a), rx = min(rx, x - a);
			res += ra;
			S.erase(*pl);
			S.insert({a, ra});
		}
	
		if (it != S.end()) {
			auto pr = it;
			auto [b, rb] = *pr;

			if (rb != INF) res -= rb;
			rb = min(rb, b - x), rx = min(rx, b - x);
			res += rb;
			S.erase(*pr);
			S.insert({b, rb});
		}
		S.insert({x, rx});

		//cout << "------------------------------" << endl;
		//for (auto [a, b] : S) {
		//	cout << a << ' ' << b << endl;
		//}

		res += rx;

		cout << res << endl;
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

