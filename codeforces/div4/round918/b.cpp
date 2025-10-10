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
		char mp[3][3];
		int ii, jj;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				cin >> mp[i][j];
				if (mp[i][j] == '?')
				{
					ii = i;
					jj = j;
				}
			}
		
		int soma = 0;
		for (int j = 0; j < 3; j++)
			if (j != jj)
				soma += mp[ii][j] - 'A';

		cout << char('A' + 3 - soma) << endl;
	}
    
    return(0);
}
