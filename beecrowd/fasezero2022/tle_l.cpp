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

ll n; 

int conta4(ll base)
{
    ll temp = n;
	int r = 0;
	while (temp > 0)
	{
		if (temp % base == 4)
			r++;
		temp /= base;
	}
	return r;
}

void solve()
{
	ll melhor = 0;
	double max4 = 0;

	for (ll i = 5; i < n; i++)
	{
		int quant4 = conta4(i);
		int quantD = log(n) / log(i) + 1;
		double prop = (double)quant4 / quantD;
		
		if (prop > max4)
		{
			max4 = prop;
			melhor = i;
		}
		else if (prop == max4 and i > melhor)
			melhor = i;
	}	

	printf("%lld, max: %.2lf, base: %lld\n", n, max4, melhor);
}

int main()
{
    _;
	while (cin >> n)
		solve();
    
    return(0);
}

