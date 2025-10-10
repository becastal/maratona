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
	int n, x; cin >> n >> x;

	// nao pensei que so brutar resolvia, da pra provar que da pela soma harmonica.
	ll res = 0;
	for (ll a = 1; a <= n and a <= x; a++) {
		for (ll b = 1; a * b <= n and a + b <= x; b++) {
			ll c1 = max(0LL, x - a - b), c2 = max(0LL, n - a * b) / (a + b);
			res += min(c1, c2);
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
