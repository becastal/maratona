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
		int a, b, c;
		cin >> a >> b >> c;

		if (c != a + 1) { cout << -1 << endl; continue; }
		if (a + b + c == 1) { cout << 0 << endl; continue; }
		
		int agr = 1, prox = 0, res = 1;
		for (int i = 0; i < a + b; i++)
		{
			if (!agr)
			{
				swap(prox, agr);
				res++;
			}
			agr--;
			prox++;
			if (i < a)
				prox++;
		}
		cout << res << endl;
	}
    
    return(0);
}
