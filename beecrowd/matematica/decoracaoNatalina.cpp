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
#define pi 3.141592654

int main()
{
    _;

	double a, b, c; 
	while (cin >> a >> b >> c)
		cout << fixed << setprecision(2) << (5 * (tan(pi * a / 180) * b + c)) << endl;
    
    return(0);
}
