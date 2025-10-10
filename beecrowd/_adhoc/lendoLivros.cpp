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

	double q, d, p;
	while (true)
	{
		cin >> q;
		if (!q)
			break;
		cin >> d >> p;
		double res = ((q * d) / (p - q)) * p;
		cout << (int)res << " pagina" << ((int)res == 1 ? "" : "s") << endl;
	}
    
    return(0);
}
