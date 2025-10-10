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
typedef pair<int, int> ii;
#define sq(x) ((x)*(x))

void solve() {
	int x, y, k;
	cin >> x >> y >> k;

	int m = min(x, y);
	cout << 0 << ' ' << 0 << ' '  << m << ' ' << m << endl;
	cout << 0 << ' ' << m << ' '  << m << ' ' << 0 << endl;

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
