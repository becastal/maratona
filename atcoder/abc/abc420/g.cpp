#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {

	ll x; cin >> x;
	ll c = 4*x - 1;

	set<ll> R;
	auto add = [&](ll a) {
		R.insert((a - c / a - 2) / 4);
	};

	for (ll d = -1; d * d <= abs(c); d += 2) {
		if (c % d) continue;

		add(d), add(-d);
		add(c / d), add(-c / d);
	}

	cout << R.size() << endl;
	for (ll i : R) cout << i << ' '; cout << endl;

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

