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
typedef long double ld;

int main()
{
    _;

	ld p, a, b, c, d; 
	cin >> p >> a >> b >> c >> d; 

	int n; cin >> n;	
	ld res = 0, mx = 0;
	for (int k = 0; k < n; k++)
	{
		ld agr = p * (sin(a * k + b) + cos(c * k + d) + 2);
		res = max(res, mx - agr);
		mx = max(mx, agr);
	}
    
	cout << res << endl;

    return(0);
}
