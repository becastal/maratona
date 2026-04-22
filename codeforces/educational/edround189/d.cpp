#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, x; cin >> n >> x;

	//for (int i = 1; i <= n; i++) {
	//	int xs = i;
	//	for (int j = i + 1; j <= n; j++) {
	//		xs ^= j;
	//		
	//		if (xs == 0 and i <= x and x <= j) {
	//			cout << "[" << i << ", " << j << "]: xs(i) = " << (i - 1) % 4 << ", xs(j) = " << j % 4 << endl;
	//		}
	//	}
	//}

	auto cont1 = [&](int a) {
		if (a <= 0) return 0LL;
		return (a + 3) / 4;
	};
	auto cont3 = [&](int a) {
		if (a <= 0) return 0LL;
		return (a + 1) / 4;
	};

	const int mod = 998244353;
	int mod1f = cont1(n) - cont1(x - 1), mod1t = cont1(x - 1);
	int mod3f = cont3(n) - cont3(x - 1), mod3t = cont3(x - 1);
	mod1f %= mod;
	mod3f %= mod;
	mod1t %= mod;
	mod3t %= mod;

	//for (int i = x; i <= n; i++) {
	//	if (i % 4 == 3) {
	//		mod3f++;
	//	}
	//	if (i % 4 == 1) {
	//		mod1f++;
	//	}
	//}

	//for (int i = 1; i < x; i++) {
	//	if (i % 4 == 3) {
	//		mod3t++;
	//	}
	//	if (i % 4 == 1) {
	//		mod1t++;
	//	}
	//}

	cout << (mod1f * mod1t % mod + mod3f * (mod3t + 1) % mod) % mod << endl;

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

