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
	ll n, l, r, k;
	cin >> n >> l >> r >> k;

	if (n & 1) return cout << l << endl, 0;

	ll b = (1LL << (64 - __builtin_clzll(l)));
	if (n > 2 and b <= r) return cout << (k <= n - 2 ? l : b) << endl, 0;

	cout << -1 << endl;

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
