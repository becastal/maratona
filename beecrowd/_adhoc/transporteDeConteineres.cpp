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

	int a, b, c; cin >> a >> b >> c;
	int x, y, z; cin >> x >> y >> z;

	int l = x / a, co = y / b, h = z / c;
	cout << l * co * h << endl;
    
    return(0);
}
