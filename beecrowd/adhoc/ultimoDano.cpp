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
		int at, ad, bt, bd, h;
		cin >> at >> ad >> bt >> bd >> h;

		int r = 0;
		bool andre = true;
		while (true)
		{
			if (r % ad == 0)
			{
				if (h - at <= 0)
				{
					andre = true;
					break;
				}
				h -= at;
			}

			if (r % bd == 0)
			{
				if (h - bt <= 0)
				{
					andre = false;
					break;
				}
				h -= bt;
			}

			r++;
		}
		cout << (andre ? "Andre" : "Beto") << endl;
	}
    
    return(0);
}
