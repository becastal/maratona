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
		int a, b, c; cin >> a >> b >> c;
		if (a < b and b > c)
			cout << "PEAK" << endl;
		else if (a < b and b < c)
			cout << "STAIR" << endl;
		else
			cout << "NONE" << endl;
	}
    
    return(0);
}
