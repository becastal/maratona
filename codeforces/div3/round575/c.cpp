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

	int menX = -1e5, maiX = 1e5;
	int menY = -1e5, maiY = 1e5;

	for (int i = 0, x, y, f1, f2, f3, f4; i < n; i++) {
		cin >> x >> y >> f1 >> f2 >> f3 >> f4;

		// U, R, D, L
		if (!f1) {
			menX = max(menX, x);
		}

		if (!f2) {
			maiY = min(maiY, y);
		}

		if (!f3) {
			maiX = min(maiX, x);
		}

		if (!f4) {
			menY = max(menY, y);
		}
	}

	if (maiX < menX or maiY < menY) {
		cout << 0 << endl;
		return;
	}

	cout << 1 << ' ' << menX << ' ' << menY<< endl;
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
