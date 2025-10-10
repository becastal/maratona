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
	int n, k; cin >> n >> k;

	map<int, pair<ll, ll>> ev;
	for (int i = 0, l, r, g; i < n; i++) {
		cin >> l >> r >> g; r++;
		ev[l].f += g, ev[l].s += 1;
		ev[r].f -= g, ev[r].s -= 1;
	}

	ll agr = 0, g = 0, res = -LINF;
	for (auto [pos, se] : ev) {
		auto [gi, dif] = se;
		agr += dif;	
		g += gi;
		if (agr <= k) res = max(res, g);
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
