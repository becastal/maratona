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

	int n, m;
	while (cin >> n >> m and n and m)
	{
		vector<pair<int, int>> v((int) 1e5 + 10);
		for (int i = 0; i < v.size(); i++)
			v[i] = {0, i};

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int ni; cin >> ni;
				v[ni].f--;
			}

		sort(v.begin(), v.end());
		int seg = v[1].f;	
		for (auto [pts, x] : v) 
		{
			if (pts == seg)
				cout << x << ' ';
			else if (!pts) break;
		}
		cout << endl;
	}
    
    return(0);
}
