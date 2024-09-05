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

	ld l, w, h, a;
	cin >> l >> w >> h >> a;

	a = (a*pi) / 180.0;
	ld total = l * w * h, neg = 0.5 * l * l * w * tan(a);
	cout << fixed << setprecision(3) << total - neg << " mL" << endl;


    return(0);
}
