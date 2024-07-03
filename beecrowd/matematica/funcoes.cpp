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
	
	int t; cin >> t;
	while (t--)
	{
		int x, y; cin >> x >> y;
		int r = pow(3 * x, 2) + pow(y, 2);
		int b = 2 * pow(x, 2) + pow(5 * y, 2);
		int c = -100 * x + pow(y, 3);

		if (r > b and r > c)
			cout << "Rafael ganhou" << endl;
		else if (b > r and b > c)
			cout << "Beto ganhou" << endl;
		else
			cout << "Carlos ganhou" << endl;
	}
    
    return(0);
}
