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

ll fat(ll a)
{
	if (!a) return 1;
	ll r = 1;
	while (a >= 2)
		r *= a--;
	return r;
}

int main()
{
    _;

	set<int> fatores;
	ll n; cin >> n;
	for (int i = 2; i < 1e6; i++)
	{
		while (n % i == 0)
		{
			n /= i;
			fatores.insert(i);
		}
	}
	if (n > 1) fatores.insert(n);

	int res = 0;
	int x = fatores.size();
	for (int i = 2; i <= x; i++)
		res += fat(x) / (fat(i) * fat(x - i));

	cout << res << endl;
    
    return(0);
}
