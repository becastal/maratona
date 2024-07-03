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

	string n;
	while (cin >> n and n != "0")
	{
		int res = 0;
		for (int i = 0; i < n.size(); i++)
			res += (fat(n.size() - i) * (n[i] - '0'));

		cout << res << endl;
	}
    
    return(0);
}
