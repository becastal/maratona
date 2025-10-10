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

	int x, y, xx, yy; 
	cin >> x >> y >> xx >> yy; 

	int dy = yy - y, dx = xx - x;
	string a = string(dy, 'U') + string(dx, 'R') + string(dy, 'D') + string(dx, 'L');
	string b = "L" + string(dy + 1, 'U') + string(dx + 1, 'R') + "D"  +
	           "R" + string(dy + 1, 'D') + string(dx + 1, 'L') + "U";

	cout << a + b << endl;
    
    return(0);
}
