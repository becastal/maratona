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
	int n, m, xa, ya, xb, yb;
	cin >> n >> m >> xa >> ya >> xb >> yb;

	if (xb < xa) return cout << "Draw" << endl, 0;
	if ((xa - xb - 1) & 1 ^ 1) {
		// alice pode ganhar
		int xc = (xa + xb + 1) / 2;
		int da = abs(xa - xc);
		int la = max(1, ya - da), ra = min(m, ya + da);

		int db = abs(xb - xc);
		int lb = max(1, yb - db), rb = min(m, yb + db);


		if (lb >= la and rb <= ra) return cout << "Alice" << endl, 0;
		else return cout << "Draw" << endl, 0;
	} else {
		// bob pode ganhar

		int xc = (xa + xb) / 2;
		int da = abs(xa - xc);
		int la = max(1, ya - da), ra = min(m, ya + da);

		int db = abs(xb - xc);
		int lb = max(1, yb - db), rb = min(m, yb + db);

		if (la >= lb and ra <= rb) return cout << "Bob" << endl, 0;
		else return cout << "Draw" << endl, 0;
	}


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

