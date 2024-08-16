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

	int n; cin >> n;
	vector<ll> v(n);
	for (ll& vi : v)
		cin >> vi;

	ll g = v[0];
	for (int i = 1; i < n; i++)
		g = mdc(g, v[i]); 

	ll res = 0;
	for (ll i = 1; i * i <= g; i++)
		if (g % i == 0)
		{
			res++;
			if (g / i != i) res++;
		}

	cout << res << endl;
    
    return(0);
}
