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
// muito puto com essa, mas confesso que tambem nunca fiz o 2p desse jeito. (sempre fiz crescendo primeiro e o while so diminuia). enfim. aprendendo.

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<ll>> mp(n, vector<ll>(m));
	for (auto& l : mp)
		for (auto& c : l)
			cin >> c;

	int melhor = 0;
	for (int i = 0; i < n; i++)
	{
		int r = 0;
		for (int l = 0; l < m; l++)
		{
			while (r < m and (l == r or abs(mp[i][r] - mp[i][r - 1]) <= 1))
				r++;
			melhor = max(melhor, r - l);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int r = 0;
		for (int l = 0; l < n; l++)
		{
			while (r < n and (l == r or abs(mp[r][i] - mp[r - 1][i]) <= 1))
				r++;
			melhor = max(melhor, r - l);
		}
	}

	cout << melhor << endl;
    
    return(0);
}


