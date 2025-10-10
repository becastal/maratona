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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int a, b, c, n; cin >> a >> b >> c >> n;

		int mx = max({a, b, c});
		cout << (3 * mx - (a + b + c) <= n and ((n - (3 * mx - (a + b + c))) % 3 == 0) ? "YES" : "NO") << endl;
	}
    
    return(0);
}
