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

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main()
{
    _;

	ll n; cin >> n;
	int k; cin >> k;
	vector<int> vruim(k), v;
	for (int& i : vruim) cin >> i;

	for (int i = 0; i < k; i++) {
		int ok = 1;
		for (int j = 0; j < k and ok; j++) {
			if (i != j) {
				ok &= vruim[i] % vruim[j] != 0;
			}
		}
		if (ok) v.push_back(vruim[i]);
	}
	k = v.size();

	// 100 3
	// 2 3 7

	// 2, 3, 7
	// 2*3, 2*7, 3*7
	// 2*3*7

	ll res = 0;
	for (int i = 1; i < (1 << k); i++) {
		ll agr = 1;
		int gcd_t = 0, int ok = 1;
		for (int j = 0; j < k and ok; j++) {
			if (i & (1 << j)) {
				if (agr > n / v[j]) ok = 0;
				else {
					agr *= v[j];
					gcd_t = gcd(gcd_t, v[j]);
				}
			}
		}
		if (agr != gcd_t and gcd_t > 1) agr /= gcd_t;

		res += ok * (__builtin_popcount(i) & 1 ? 1LL : -1LL) * (n / agr);
	}
	cout << n - res << endl;
    
    return 0;
}

