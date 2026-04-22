#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int l, r, d, u; cin >> l >> r >> d >> u;

	auto pares = [](int a, int b) {
		if (a > b) return 0LL;
		return (b - a + 1 + (a % 2 == 0)) / 2;
	};

	int p = pares(l, r), res = 0;

	for (int y = d; y <= u; y++) {
		int t = abs(y);

		int a = max(l, -t);
		int b = min(r,  t);

		int tam = max(0LL, b - a + 1);
		int dentro = pares(a, b);

		if (t % 2 == 0) {
			res += tam + (p - dentro);
		} else {
			res += p - dentro;
		}
	}

	cout << res << endl;
	return 0;
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
