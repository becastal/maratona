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

	int b, t; cin >> b >> t;
	int a = double((b + t) * 70) / 2.0;

	if (a == 11200 / 2.0)
		cout << 0 << endl;
	else if (a > 11200 / 2.0)
		cout << 1 << endl;
	else
		cout << 2 << endl;
    
    return(0);
}
