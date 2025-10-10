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

	if (n < 4) {
		cout << -1 << endl;
		return;
	}

	for (int i = n; i >= 1; --i) {
		if (i & 1) cout << i << ' ';
	}
	cout << 4 << ' ' << 2 << ' ';
	for (int i = 6; i <= n; i += 2) {
		cout << i << ' ';
	}
	cout << endl;	
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
