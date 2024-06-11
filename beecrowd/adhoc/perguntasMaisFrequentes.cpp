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

	int n, k;
	while (cin >> n >> k and n and k)
	{
		vector<int> v(1e2 + 10, 0);
		for (int i = 0; i < n; i++)
		{
			int vi; cin >> vi;
			v[vi]++;
		}
		
		int c = 0;
		for (auto vi : v)
			if (vi >= k)
				c++;

		cout << c << endl;
	}
    
    return(0);
}
