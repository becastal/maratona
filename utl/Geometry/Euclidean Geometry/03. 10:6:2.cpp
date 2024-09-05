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
typedef double ld;
const ld pi = acos(-1);

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		ld l; cin >> l;
		ld w = (6.0 / 10.0) * l, r = l / 5.0;
		
		ld red = pi * r * r;
		ld green = l * w - red;

		cout << fixed << setprecision(2) << red << ' ' << green << endl;
	}
    
    return(0);
}
