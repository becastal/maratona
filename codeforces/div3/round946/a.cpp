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
		int x, y, telas = 0; cin >> y >> x;

		if (x or y)
		{
			while (x > 1)
				x -= 2, y -= 7, telas++;

			if (x == 1)
				x = 0, y -= 11, telas++;

			if (!x and y > 0)
				telas += (y + 15 - 1) / 15;
		}

		cout << telas << endl;
	}
    
    return(0);
}
