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
		vector<int> v(n, 0);
		int c = 0;
		for (int i = 0; i < m; i++)
		{
			int vi; cin >> vi; vi--;
			if (v[vi] == 1)
				c++;
			v[vi]++;
		}
		cout << c << endl;
	}
    
    return(0);
}
