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
	ll x, y = 0; cin >> x;

	int n = 64 - __builtin_clzll(x);
	for (int l = 0, r = n-1; l <= r; l++, r--) {
		if (x & (1LL << r)) {
			y |= (1LL << l);
			y |= (1LL << r);
		}
	}

	//for (int i = n-1; i >= 0; i--) {
	//	cout << !!(x & (1LL << i));
	//}
	//cout << endl;
	//for (int i = n-1; i >= 0; i--) {
	//	cout << !!(y & (1LL << i));
	//}
	//cout << endl;
	//dbg(y);
	if (y <= x) return cout << y << endl, 0;

	x -= (1LL << (n / 2));
	int m = 64 - __builtin_clzll(x);

	ll y_ = 0;
	for (int l = 0, r = m-1; l <= r; l++, r--) {
		if (x & (1LL << r)) {
			y_ |= (1LL << l);
			y_ |= (1LL << r);
		}
	}
	cout << max(y_, (1LL << (n-1)) -1) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
