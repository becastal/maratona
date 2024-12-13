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
	int n; cin >> n;

	if (n <= 4) return cout << -1 << endl, 0;

	for (int i = 1; i <= n; i += 2) {
		if (i != 5) cout << i << ' ';
	}
	cout << 5 << ' ' << 4 << ' ';
	for (int i = 2; i <= n; i += 2) {
		if (i != 4) cout << i << ' ';
	}
	cout << endl;

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
