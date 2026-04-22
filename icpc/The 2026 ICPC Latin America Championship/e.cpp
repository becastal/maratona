#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	int menor = LLONG_MIN, maior = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		char tp; cin >> tp;

		if (tp == 'E') {
			if ((l + r) % 2 == 1) return cout << "*" << endl, 0;

			int m = (l + r) / 2;
			menor = max(menor, m);
			maior = min(maior, m);
		} else if (tp == 'A') {
			if ((l + r) % 2 == 0) {
				maior = min(maior, (l + r) / 2 - 1);
			} else {
				maior = min(maior, (l + r) / 2);
			}
		} else if (tp == 'B') {
			menor = max(menor, (l + r) / 2 + 1);
		}
		if (menor > maior) return cout << "*" << endl, 0;
	}
	cout << menor << " " << maior << endl;

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

