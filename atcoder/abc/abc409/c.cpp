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
	int n, l; cin >> n >> l;

	vector<ll> f(l, 0); f[0] = 1;
	for (ll i = 0, s = 0, x; i < n - 1; i++) {
		cin >> x;
		s += x;
		f[s % l]++;
	}
	if (l % 3 != 0) return cout << 0 << endl, 0;

	ll res = 0;
	for (int i = 0; i < l / 3; i++) {
		res += f[i] * f[i + l / 3] * f[i + 2 * l / 3];
	}
	cout << res << endl;

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
