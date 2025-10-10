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
	int n; cin >> n;
	vector<int> v(n), pri(n, 0), ult(n, 0);

	for (int& i : v) cin >> i;

	set<int> pri_, ult_;
	for (int i = n-1; i >= 0; i--) {
		ult[i] = !ult_.count(v[i]);
		ult_.insert(v[i]);
	}

	ll res = 0;
	int u = count(ult.begin(), ult.end(), 1);
	for (int i = 0; i < n; i++) {
		if (!pri_.count(v[i])) {
			pri_.insert(v[i]);
			res += u;
		}
		u -= ult[i];
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
