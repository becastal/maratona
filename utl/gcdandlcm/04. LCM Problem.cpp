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

ll mdc(ll a, ll b)
{
	return b == 0 ? a : mdc(b, a % b);
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		int l, r; cin >> l >> r;
		if (l * 2 > r)
			cout << -1 << ' ' << -1 << endl;
		else
			cout << l << ' ' << l * 2 << endl;
	}
    
    return(0);
}
