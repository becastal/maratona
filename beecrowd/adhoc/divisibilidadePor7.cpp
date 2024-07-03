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

int dig(ll x)
{
	int res = 0;
	while (x)
	{
		res++;
		x/=10;
	}
	return res;
}

int main()
{
    _;

	ll n; cin >> n;
	while (dig(n) > 1)
	{
		cout << n << endl;
		n = ((n - (n % 10)) / 10) * 3 + n % 10;
	}
	cout << n << endl;
    
    return(0);
}
