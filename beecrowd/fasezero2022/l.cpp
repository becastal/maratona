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

ll polinomio(ll d, int pos, int constante, int grau) 
{
	ll soma = 0;
	for (int i = 0; i <= grau; i++)
	{
		if (i == pos)
			soma += constante * pow(d, i);
		else
			soma += 4 * pow(d, i);
	}
	return soma;	
}

ll emzsolucaopolinomio(ll n, int grau)
{
	for (int d = 5; d <= 1e2; d++)
		for (int i = 0; i <= grau; i++)
			for (int j = 1; j <= 4; j++)
			{
				ll resp = polinomio(d, i, j, grau);
				if (resp == n) return d;
			}

	return LINF;
}

ll solve()
{
	ll n; cin >> n;

	if (n <= 8) 
		return n - 1;

	if ((n - 4) % 4 == 0)
		return (n - 4) / 4;

	for (int i = 10; i >= 2; i--)
	{
		ll di = emzsolucaopolinomio(n, i);
		if (di != LINF) return di;
	}

	return n - 4;
}

int main()
{
    _;
	ll r = solve();
	cout << r << endl;
    
    return(0);
}
