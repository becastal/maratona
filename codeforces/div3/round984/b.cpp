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
	int n, k; cin >> n >> k;
	vector<ll> v(k+1);
	for (int i = 0, bi, xi; i < k; i++) {
		cin >> bi >> xi;
		v[bi] += xi;
	}

	sort(v.rbegin(), v.rend());
	ll res = 0;
	for (int i = 0; i < min(n, k); i++) {
		res += v[i];
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
