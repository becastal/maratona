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
	ll n, d; cin >> n >> d;

	if (d <= n) return cout << "YES" << endl, 0;
	for (ll i = 0; i * i <= d; i++) {
		if ((d + i) / (i + 1) + i <= n) return cout << "YES" << endl, 0;
	}
	cout << "NO" << endl;

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
