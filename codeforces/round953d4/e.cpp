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
	while (t--)
	{
		int x, y, z; cin >> x >> y >> z;
		ll k, res = 0; cin >> k;

		for (int a = 1; a <= x; a++)
			for (int b = 1; b <= y; b++)
			{
				if (k % (a * b)) continue;
				ll c = k / (a * b);
				if (c > z) continue;
				res = max(res, (x - a + 1) * (y - b + 1) * (z - c + 1));
			}

		cout << res << endl;
	}
    
    return(0);
}
