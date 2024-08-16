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

	map<int, vector<int>> g;	

	for (vector<int> vi : edges)
	{
		g[vi[0]].push_back(vi[1]);
		g[vi[1]].push_back(vi[0]);
	}

	for (auto [i, vi] : g)
		if ((int)vi.size() == (int)g.size() - 1)
			return i;
    
    return(0);
}
