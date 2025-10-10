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
	int n; cin >> n;
	vector<ll> d(n), a(n), c(n), l(n, 0);

	for (ll& i : d) cin >> i;
	for (ll& i : a) cin >> i;
	for (ll& i : c) cin >> i;
	for (int i = 0; i < n-1; i++) cin >> l[i];
	
	priority_queue<pair<ll, ll>> pq;
	ll off = 0, res = 0;
	for (int i = 0; i < n; i++) {
		pq.emplace(-(c[i] - off), a[i]);

		while (pq.size() and d[i]) {
			auto [cj, aj] = pq.top(); pq.pop(); cj = -cj;
			ll toma = min(d[i], aj);
			d[i] -= toma, aj -= toma;
			res += toma * (cj + off);
			
			if (aj) pq.emplace(-cj, aj);
		}
		
		off += l[i];
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
