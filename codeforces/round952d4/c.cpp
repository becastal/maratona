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

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<ll> v(n);
		for (ll& vi : v)
			cin >> vi;

		ll soma = 0, maior = 0, res = 0;
		for (int i = 0; i < n; i++)
		{
			soma += v[i];	
			maior = max(maior, v[i]);
			if (soma - maior == maior)
				res++;
		}
		cout << res << endl;
	}
    
    return(0);
}
