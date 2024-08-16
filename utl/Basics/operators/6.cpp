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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a %= 100, b %= 100, c %= 100, d %= 100;

	int r = (a * b * c * d) % 100;

	if (!r) cout << "00" << endl;
	else if (r < 10) cout << '0' << r << endl;
	else cout << r << endl;
    
    return(0);
}
