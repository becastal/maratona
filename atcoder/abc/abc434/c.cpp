#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, h; cin >> n >> h;
	
	int a = h, b = h, ruim = 0;
	for (int i = 0, t, l, r, ult = 0; i < n; i++) {
		cin >> t >> l >> r;
		if (ruim) continue;
		int d = t - ult;
		a -= d, b += d;
		a = max(a, l);
		b = min(b, r);

		if (a > b) {
			ruim = 1;
		}

		ult = t;
	}
	cout << (ruim ? "No" : "Yes") << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

