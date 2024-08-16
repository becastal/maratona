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

int mdc(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    _;

	int a, b; cin >> a >> b;
	mdc(a, b);
    
    return(0);
}
