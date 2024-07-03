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

int x, y;

ll mdc(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int solve()
{
	if (x == y)
		return 4;

	if (x < y)
		swap(x, y);

	return 2 * (x / mdc(x, y)) + 2 * (y / mdc(x, y));
}

int main()
{
    _;

	while (cin >> x >> y)
		cout << solve() << endl;
    
    return(0);
}
