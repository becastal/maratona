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
		int c = 0;
		while (n--)
		{
			double q, a, b; cin >> q >> a >> b;
			cout << "Size #" << ++c << ":\nIce Cream Used: " << fixed << setprecision(2) << q * (((a + b) * 5.0) / 2.0) << " cm2" << endl;
		}
		
		cout << endl;
	}
    
    return(0);
}
