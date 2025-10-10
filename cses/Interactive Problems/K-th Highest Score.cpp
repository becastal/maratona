#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	auto query = [](int tp, int i) {
		cout << (tp ? 'S' : 'F') << ' ' << i << endl;
		int x; cin >> x; return x;	
	};
	int n, k; cin >> n >> k;

	int l = max(1, k - n), r = min(n, k - 1);
	while (l <= r) {
		int m = l + (r - l) / 2;

		int f = query(0, m), s = query(1, k - m);
		if (f > s) {
			r = m - 1;
		} else {
			l = m + 1;
			res = m;
		}
	}

	return(0);
}

int main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
