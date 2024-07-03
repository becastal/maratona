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
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

ll mmc(ll a, ll b)
{
	return (a / mdc(a, b)) * b;
}

int main()
{
    _;
	
	ll n, l; cin >> n >> l;

	ll t = 1;
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		t = mmc(t, x);
	}

	ll maiori = 1;
	ll maior = t;

	for (ll i = 2; i <= l; i++)
	{
		ll v = mmc(t, i);
		if (v <= l and v > maior)
		{
			maiori = i;
			maior = v;
		}
	}

	cout << maiori << endl;
    
    return(0);
}
