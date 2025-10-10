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
	ll n; cin >> n;
	vector<ll> v(n), a(n+1, 0), b(n+1, 0);

	for (ll& i : v) cin >> i;
	for (ll i = 1; i <= n; i++) {
		a[i] = a[i-1] + v[i-1];
	}

	map<ll, ll> B;
	for (int i = n-1; i >= 0; i--) {
		b[i] = b[i+1] + v[i];
		B[b[i]] = i;
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		B.erase(b[i]);

		if (B.count(a[i+1])) {
			res = max(res, i + (n - B[a[i+1]] + 1));
		};
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
