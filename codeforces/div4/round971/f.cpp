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
	int n, q; cin >> n >> q;
	
	vector<ll> v(n), pre = {0};
	for (ll& i : v) cin >> i;

	for (ll i : v) {
		pre.push_back(pre.back() + i);
	}
	for (ll i : v) {
		pre.push_back(pre.back() + i);
	}

	while (q--) {
		ll l, r; cin >> l >> r; l--, r--;
		ll i = l / n, j = r / n;
		l %= n, r %= n;

		cout << pre[n] * (j-i+1) - (pre[i+l] - pre[i]) - (pre[j+n]- pre[j+r+1]) << endl;
	}
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
