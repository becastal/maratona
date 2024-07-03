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

	int h1, m1, h2, m2;
	while (cin >> h1 >> m1 >> h2 >> m2 and !(h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0))
	{
		int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
		if (t1 < t2)
			cout << t2 - t1 << endl;
		else
			cout << 24 * 60 - t1 + t2 << endl;
	}
    
    return(0);
}
