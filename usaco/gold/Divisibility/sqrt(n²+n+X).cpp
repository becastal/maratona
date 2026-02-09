#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll x; cin >> x;

	set<ll> R;
	auto add = [&](ll d) {
	    R.insert((d - x / d - 2) / 4);
	};

	x = 4 * x - 1;
	ll d = -1;
	while (d * d <= abs(x)) {
		d += 2;
		if (x % d != 0) continue;
		add(d), add(-d);
		add(x / d), add(-x / d);
	}
	
	cout << (int)R.size() << endl;
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

