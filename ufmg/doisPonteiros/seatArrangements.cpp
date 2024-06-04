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

	int n, m, k; cin >> n >> m >> k;
	vector<vector<char>> mp(n, vector<char>(m));
	for (auto& rw : mp)
		for (auto& cl : rw)
			cin >> cl;

	int c = 0;

	for (auto rw : mp)
	{
		int l = 0, tam = 0;
		for (int r = 0; r < m; r++)
		{
			if (rw[r] == '*')
				l = r + 1, tam = 0;
			else
			{
				if (tam < k - 1)
					tam++;
				else
					c++, l++;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int l = 0, tam = 0;
		for (int r = 0; r < n; r++)
		{
			if (mp[r][i] == '*')
				l = r + 1, tam = 0;
			else
			{
				if (tam < k - 1)
					tam++;
				else
					c++, l++;
			}
		}
	}

	if (k == 1) c /= 2;
	cout << c << endl;
    
    return(0);
}

