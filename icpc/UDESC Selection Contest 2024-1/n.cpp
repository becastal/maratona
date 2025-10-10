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
	int n, m, q; cin >> n >> m >> q;

	set<int> a, b;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int x, y; cin >> x >> y;
			a.insert(x);
			b.insert(y);
		} else {
			int xi, yi; cin >> xi >> yi;
			int xf, yf; cin >> xf >> yf;
			cout << ((a.count(xi) or b.count(yi)) and (a.count(xf) or b.count(yf)) ? "SIM" : "NAO") << endl;
		}
	}

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
