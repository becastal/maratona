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
		if (n % 2 == 0)
			cout << n / 2 << ' ' << n / 2 << endl;
		else
		{
			vector<int> divs;			
			for (int i = 1; i * i <= n; i++)
				if (n % i == 0)
				{
					divs.push_back(i);
					if (n / i != i) divs.push_back(n / i);
				}

			int menor = INF, res;
			for (int i : divs)
				if (i and n - i and lcm(i, n - i) < menor)
				{
					menor = lcm(i, n - i);
					res = i;
				}

			cout << res << ' ' << n - res << endl;
		}
	}
    
    return(0);
}
