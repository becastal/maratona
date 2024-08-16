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
		int n, m; cin >> n >> m;
		vector<vector<char>> mp(n, vector<char>(m));
		vector<pair<int, int>> p;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> mp[i][j];
				if (mp[i][j] == '#')
					p.push_back({i, j});
			}
		
		sort(p.begin(), p.end());

		auto a = p[0], b = p.back();
		cout << ((a.f + b.f) / 2) + 1 << ' ' << a.s + 1 << endl;
	}
    
    return(0);
}
