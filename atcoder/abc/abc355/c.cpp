#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, t; cin >> n >> t;

	vector<int> Ca(n), Cb(n);
	int diag_a = 0, diag_b = 0;

	for (int i = 0, x; i < t; i++) {
		cin >> x; x--;
		int a = x / n, b = x % n;

		auto f = [&](int& aa) {
			if (++aa == n) {
				cout << (i + 1) << endl;
				exit(0);
			}
		};
		f(Ca[a]);
		f(Cb[b]);
		if (a == b) f(diag_a);
		if (a + b == n-1) f(diag_b);
	}

	cout << -1 << endl;
	
	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

