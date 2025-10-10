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

	int n;
	while (cin >> n and n)
	{
		pair<int, int> p = {0, 0};
		for (int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			p.f += (x > y ? 1 : 0);
			p.s += (y > x ? 1 : 0);
		}
		cout << p.f << ' ' << p.s << endl;
	}
    
    return(0);
}
