#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int solve() {
	ll n, d, res = LLONG_MAX; cin >> n >> d;

	for (ll k = 0; k <= 60; k++) {
		ll a = (1LL << k);
		if (a > n) break;

		ll b = n - a;
		if (b % d) continue;

		ll h = b / d;
		ll q = h >> (k + 1), mask = ((1LL << (k + 1)) - 1LL);
		res = min(res, k + 2 * q + __builtin_popcountll(h & mask));
	}
	if (res == LLONG_MAX) res = -1;
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

