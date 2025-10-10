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
	int x, n; cin >> x >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0, d; i < n; i++) {
		cin >> d;
		pq.emplace(d);
	}

	ll res = 0;
	while (pq.size() >= 2) {
		ll a = pq.top(); pq.pop();
		a += pq.top(); pq.pop();

		res += a;
		pq.emplace(a);
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
