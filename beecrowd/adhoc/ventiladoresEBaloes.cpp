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
typedef pair<int, int> ii;

int main()
{
    _;

	int l, c, p;
	while (cin >> l >> c >> p and l and c and p)
	{
		vector<vector<int>> mp(l, vector<int>(c));

		for (auto& li : mp)
			for (auto& ci : li)
				cin >> ci;

		ii b = {-1, p - 1};
		bool popou = false;
		for (int i = 0; i < l; i++)
		{
			b.f = i;
			int s = 0;
			for (int j = b.s; j >= 0; j--)
				if (mp[i][j])
				{
					s += mp[i][j];
					break;
				}

			for (int j = b.s; j < c; j++)
				if (mp[i][j])
				{
					s -= mp[i][j];
					break;
				}
			b.s += s;

			if (mp[b.f][b.s])
			{
				popou = true;
				break;
			}
		}

		if (popou)
			cout << "BOOM " << b.f + 1 << ' ' << b.s + 1 << endl;
		else
			cout << "OUT " << b.s + 1 << endl;
	}
    
    return(0);
}
