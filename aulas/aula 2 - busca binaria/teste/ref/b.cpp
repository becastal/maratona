#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll h) {
	ll Spa1 = (0 + (h - 1)) * h / 2;
	ll Spa2 = (2 + (2 * h)) * h / 2;
	return Spa1 + Spa2;
}

int main() {
	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		ll cartas_tenho; cin >> cartas_tenho;

		ll l = 0, r = (ll)1e9, h = 0;

		while (l <= r) {
			ll m = l + (r - l) / 2;

			ll cartas_pra_altura_m = f(m);
			if (cartas_pra_altura_m > cartas_tenho) {
				r = m - 1;
			} else {
				h = m;
				l = m + 1;
			}
		}

		cout << h << "\n";
	}
	
	return 0;
}
