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
	int a, x, y; cin >> a >> x >> y;
	for (int i = -1000; i <= 1000; i++) {
		if (i != a and abs(i - x) < abs(a - x) and abs(i - y) < abs(a - y)) return cout << "YES" << endl, 0;
	}
	cout << "NO" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
