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

	// bus : dois peso 1 e resto peso 2;
	// ring: todos peso 2;
	// star: todos com peso 1 menos 1;
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> lig((int)1e6 + 10, 0);
	for (int i = 0; i < n; i++)
		lig[(int)g[i].size()]++;
		
	if (lig[2] == n)
		cout << "ring topology" << endl;
	else if (lig[1] == 2 and lig[2] == n - 2)
		cout << "bus topology" << endl;
	else if (lig[1] == n - 1)
		cout << "star topology" << endl;
	else
		cout << "unknown topology" << endl;
    
    return(0);
}
