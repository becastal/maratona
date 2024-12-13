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

void solve() {
	ll x, m; cin >> x >> m;

	int res = 0;
	for (ll i = 1; i <= min(2LL*x, m); i++) {
		if (i != x and ((x % (x^i) == 0) or (i % (x^i) == 0))) {
			res++;
		}
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
