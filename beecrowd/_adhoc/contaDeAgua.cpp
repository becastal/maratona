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

	vector<pair<int, int>> f = { {0, 10}, {1, 20}, {2, 70}, {5, 1e4} }; 
	int n, r = 0; cin >> n;

	for (int i = 0; i < f.size(); i++)
	{
		r += min(n, f[i].s) * f[i].f;
		n -= min(n, f[i].s);
		if (!n) break;
	}

	r += 7;
	cout << r << endl;
    
    return(0);
}
