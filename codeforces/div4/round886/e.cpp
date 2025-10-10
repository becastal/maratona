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
	int n; ll c; cin >> n >> c;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	ll l = 1, r = 1e10;
	while (l <= r) {
		ll m = l + r >> 1;

		ll agr = 0;
		for (int i = 0; i < n; i++) {
			agr += (v[i] + 2 * m) * (v[i] + 2 * m);
			if (agr > c) break;
		}

		if (agr == c) {
			cout << m << endl;
			return;
		}
		if (agr > c) {
			r = m-1;
		} else {
			l = m+1;
		}
	};
	assert(0);	
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
