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
	int x, y, k;
	cin >> x >> y >> k;

	int dx = (x + k - 1) / k;
	int dy = (y + k - 1) / k;

	if (dy >= dx) {
		cout << 2*dy << endl;	
	} else {
		cout << 2*dx -1 << endl;	
	}
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
