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
typedef double ld;

void solve() {
	int n; cin >> n;
	vector<ld> v(n);
	for (ld& i : v) cin >> i;
	sort(v.rbegin(), v.rend());

	ld res = 0;
	for (int i = 0; i < n-2; i++) {
		if (v[i] > v[i+1] + v[i+2]) continue;

		ld s = (v[i] + v[i+1] + v[i+2]) / 2.0;
		res = max(res, sqrt(s * (s-v[i]) * (s-v[i+1]) * (s-v[i+2])));
	}

	cout << fixed << setprecision(2) << res << endl;
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
