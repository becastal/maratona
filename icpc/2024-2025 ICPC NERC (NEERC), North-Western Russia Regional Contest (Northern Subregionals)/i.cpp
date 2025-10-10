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

	vector<int> h(n), p(n);
	for (int& i : h) cin >> i;
	for (int& i : p) cin >> i;

	vector<pair<int, int>> v(n);
	
	for (int i = 0; i < n; i++) {
		v[i].f = h[i], v[i].s = p[i];
		if (v[i].f > v[i].s) return cout << -1 << endl, 0;
	}
	sort(v.begin(), v.end());	

	int res = 0;
	for (int i = 0; i < n; i++) {
		v[i].s -= res;

		//cout << "(" << v[i].f << ", " << v[i].s << ")" << endl;
		if (v[i].s < v[i].f) return cout << -1 << endl, 0;
		res += v[i].s - v[i].f;
	}
	cout << res << endl;

	return 0;
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

