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

ll digitos(ll x)
{
	int r = 0;
	while (x > 0)
	{
		r++;
		x /= 10;
	}
	return r;
}

int main()
{
    _;

	ll n, m, u;
	scanf("%lld%lld", &n, &m);

	set<ll> pq;
	pq.insert(n);
	while (!pq.empty())
	{
		u = *pq.begin(); pq.erase(u);
		if (u % m == 0) break;

		int dig = digitos(u);
		if (dig >= 18) continue;

		for (int i = 0; i <= 9; i++)
			pq.insert(u * 10 + i);

		for (int i = 1; i <= 9; i++)
			pq.insert(i * pow(10, dig) + u);
	}

	printf("%lld\n", u);
    
    return(0);
}
