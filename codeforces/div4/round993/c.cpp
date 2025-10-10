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
		int m, a, b, c;
		cin >> m >> a >> b >> c;

		int r1 = max(0, m-a);
		int r2 = max(0, m-b);

		int res = 2*m - max(0, r1 + r2 - c);
		cout << res << endl;
	}
    
    return(0);
}
