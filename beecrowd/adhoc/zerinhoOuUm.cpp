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

int a, b, c;

char solve()
{
	if (a == b and b == c)
		return '*';

	int procura = 0;
	if (a + b + c == 1)
		procura = 1;

	if (a == procura)
		return 'A';
	if (b == procura)
		return 'B';
	if (c == procura)
		return 'C';

	return '*';
}

int main()
{
    _;

	while (cin >> a >> b >> c)
		cout << solve() << endl;
    
    return(0);
}
