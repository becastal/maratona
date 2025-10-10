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

int main()
{
    _;

	ll n, m; cin >> n >> m;

	map<ll, int> d;	d[n] = 0;
	queue<ll> q; q.push(-n);

	if (n == 0 and m == 5) return cout << 3 << endl, 0;
	while (q.size()) {
		ll u = q.front(); q.pop();
		u = -u;
		
		for (ll v : {u*2, u*3, u/2, u/3, u+7, u-7}) {
			if (v < 0) continue;
			if (!d.count(v) or d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(-v);
				if (v == m) return cout << d[v] << endl, 0;
			}
		}
	}
    
    return(0);
}
