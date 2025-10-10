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

	int m, k;
	while (cin >> m >> k)
	{
		vector<int> v(m), vis(1e4+10, 0);

		for (auto& vi : v)
			cin >> vi;

		int rel = 0, vistos = 0;	
		for (int i = 0; i < k; i++)
		{
			int ki; cin >> ki; ki--;
			if (vistos < m) rel += v[ki];
			if (vis[ki] == 0)
			{
				vis[ki] = 1;
				vistos++;
			}
		}

		cout << (vistos < m ? -1 : rel) << endl;
	}
    
    return(0);
}
