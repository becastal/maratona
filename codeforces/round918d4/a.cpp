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
		vector<int> c(20, 0);
		for (int i = 0; i < 3; i++)
		{
			int ai; cin >> ai;
			c[ai]++;
		}
		for (int i = 0; i < 20; i++)
			if (c[i] == 1)
			{
				cout << i << endl;
				break;
			}
	}
    
    return(0);
}
