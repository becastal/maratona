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

	map<int, int> f;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		f[x]++;
	}

	int res = -INF;
	for (auto [a, b] : f) {
		res = max(res, max(min(b-1, (int)f.size()), min(b, (int)f.size()-1)));
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
