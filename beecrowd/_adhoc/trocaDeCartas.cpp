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
		set<int> a, b;

		for (int i = 0; i < n; i++)
		{
			int ni; cin >> ni;
			a.insert(ni);
		}

		for (int i = 0; i < m; i++)
		{
			int ni; cin >> ni;
			b.insert(ni);
		}

		int ra = 0;
		for (int i : a)
			ra += !b.count(i);

		int rb = 0;
		for (int i : b)
			rb += !a.count(i);

		cout << min(ra, rb) << endl;
	}
    
    return(0);
}
