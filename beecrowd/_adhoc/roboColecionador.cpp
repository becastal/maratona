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

int n, m, s;
vector<vector<char>> mp;
vector<pair<int, int>> movimentos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valido(pair<int, int> a)
{
	return a.f >= 0 and a.s >= 0 and a.f < n and a.s < m and mp[a.f][a.s] != '#';
}

int main()
{
    _;

	while (cin >> n >> m >> s and n and m and s)
	{
		char ini;
		pair<int, int> pos;
		mp.clear();
		mp.resize(n, vector<char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> mp[i][j];
				if (mp[i][j] > 'A' and mp[i][j] < 'Z')
				{
					ini = mp[i][j];
					pos = {i, j};
				}
			}

		int dir = (ini == 'N' ? 3 : (ini == 'S' ? 1 : (ini == 'L' ? 0 : 2)));
		int res = 0;
		while (s--)
		{
			char c; cin >> c;
			if (c == 'D')
				dir++, dir %= 4;
			else if (c == 'E')
			{
				dir--;
				if (dir == -1) dir = 3;
			}
			else if (c == 'F')
			{
				pair<int, int> npos = {pos.f + movimentos[dir].f, pos.s + movimentos[dir].s};
				if (valido(npos))
				{
					if (mp[npos.f][npos.s] == '*')
					{
						res++;
						mp[npos.f][npos.s] = '.';
					}
					pos = npos;
				}
			}
		}
		cout << res << endl;
	}
    
    return(0);
}
