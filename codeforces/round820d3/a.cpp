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
		int a, b, c; cin >> a >> b >> c;
		int da = abs(a - 1);
		int db = abs(b - c) + abs(c - 1);

		if (da == db) cout << 3 << endl;
		else cout << (da < db ? 1 : 2) << endl;
	}
    
    return(0);
}
