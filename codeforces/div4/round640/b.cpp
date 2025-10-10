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

int solve() {
	int n, k; cin >> n >> k;

	// varios 1s e o que sobrar.
	// sempre sei fazer k, k+2, k+4, k+6
	if (n >= k and (n - k) % 2 == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < k-1; i++) {
			cout << 1 << ' ';
		}
		return cout << n - (k - 1) << endl, 0;
	}

	// se nao, teria que fazer
	// 2k, 2k+2, 2k+4
	if (n >= 2 * k and (n - 2*k) % 2 == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < k-1; i++) {
			cout << 2 << ' ';
		}
		return cout << n - 2 * (k - 1) << endl, 0;
	}

	cout << "NO" << endl;
	return 0;
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
