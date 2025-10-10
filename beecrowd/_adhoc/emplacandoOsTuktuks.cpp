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
		int c, d; cin >> c >> d;
		if (!c and !d)
		{
			cout << 0 << endl;
			continue;
		}
		cout << ll(pow(26, c) * pow(10, d)) << endl;
	}
    
    return(0);
}
