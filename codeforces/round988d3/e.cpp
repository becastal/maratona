#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	auto f = [](int l, int r) {
		if (r - l <= 1) return 0;
		cout << "? " << l+1 << " " << r << endl;
		int res; cin >> res;
		return res;
	};

	int n; cin >> n;
	int x = f(0, n);
	if (x == 0) return cout << "! IMPOSSIBLE" << endl, 0;

	string res = "";
	for (int i = 0; i < n; i++) {
		int y = f(i+1, n);
		if (x == y) {
			res.push_back('1');
		} else {
			res.push_back('0');
			if (y == 0) {
				res += string(x, '1');
				res.resize(n, '0');
				break;
			}
		}
		x = y;
	}

	return cout << "! " << res << endl, 0;
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
