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

void solve() {
	int n; cin >> n;
	if (n & 1) {
		cout << n << endl << "2 1 ";
		for (int i = 3; i <= n; i++) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}

	int x = (1 << (31 - __builtin_clz(n)));
	cout << (x | (x-1)) << endl;

	if (x == n) {
		cout << "2 1 ";
		for (int i = 3; i <= n; i++) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (i != x-1) cout << i << ' ';
	}
	cout << x-1 << endl;
}

int main()
{
    _;
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return 0;
}

