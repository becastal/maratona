#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	__int128_t g, m, d, k, v;

	auto get = [&](__int128_t& a) {
		int b; cin >> b;
		a = b;
	};
	get(g);
	get(m);
	get(d);
	get(k);
	get(v);

	__int128_t rv = 0;
	if (k * v <= (m - g)) {
		rv = d * k * v + (m - g) - k * v;
	} else {
		rv = d * (m - g);
	}
	cout << (rv >= g * v ? "Yes" : "No") << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

