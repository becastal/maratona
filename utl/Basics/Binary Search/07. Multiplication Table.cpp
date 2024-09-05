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

	ll n; cin >> n;
	ll l = 1, r = n * n;

	while (l < r)
	{
		ll m = (l + r) / 2;
		ll aux = 0;
		for (ll i = 1; i <= n; i++)
			aux += min(n, m / i);

		if (aux >= (n * n + 1) / 2)
			r = m;
		else
			l = m + 1;
	}
	cout << r << endl;
    
    return(0);
}
