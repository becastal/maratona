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

	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2 and x1)
	{
		if (x1 == x2 and y1 == y2)
			puts("0");
		else if (x1 == x2 or y1 == y2 or (abs(x1 - x2) == abs(y1 - y2)))
			puts("1");
		else
			puts("2");
	}
    
    return(0);
}
