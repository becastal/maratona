#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	ll m; cin >> m;
	int n; cin >> n;

	vector<ll> A(n), B(n);
	priority_queue<array<ll, 3>> P;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		P.push({B[i] - A[i], B[i], -A[i]});
	}

	ll res = 0;
	while (m and P.size()) {
		auto [d, b, a] = P.top(); P.pop();
		a *= -1;

		if (a > m) continue;
		ll x = 1 + ((m - a) / (a - b));
		res += x;
		m -= x * a, m += x * b;
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
