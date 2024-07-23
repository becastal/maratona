#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const ld pi = acos(-1.0);

int main()
{
    _;

	double r; cin >> r;
	ld alf = asin(3.0 / 5.0);

	ld a = alf * r * r;
	ld b = 0.5 * sin(pi - 2.0 * alf) * r * r;

	cout << fixed << setprecision(10) << a + b << endl;
    
    return(0);
}
