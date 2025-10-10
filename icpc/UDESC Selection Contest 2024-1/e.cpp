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

const int MAX = 3e5+10;
int g[MAX];

int solve() {
	int n, q; cin >> n >> q;


	g[0] = 0;
	int pos = 1;
	for (int i = 0, x; i < n; i++, pos++) {
		cin >> x;
		g[pos] = gcd(x, g[pos-1]);
	}

	for (int i = 0, tp; i < q; i++) {
		cin >> tp;

		if (tp == 1) {
			int x; cin >> x;
			g[pos] = gcd(x, g[pos-1]);
			pos++;
		} else if (tp == 2) {
			int k; cin >> k;
			pos -= k;
		} else if (tp == 3) {
			int x; cin >> x;
			cout << (g[pos-1] % x == 0 ? "SIM" : "NAO") << endl;
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
