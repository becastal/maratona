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

ll cartas(ll n)
{
	ll an = 2 + (n - 1) * 3;
	return ((2 + an) * n) / 2;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		ll c; cin >> c;

		ll l = 1, r = 1e9 + 10;
		for (int i = 0; i < 1000; i++)
		{
			ll m = (l + r) / 2;

			if (cartas(m) > c)
				r = m;
			else
				l = m;
		}

	 	cout << l << endl;
	}
	
    
    return(0);
}
