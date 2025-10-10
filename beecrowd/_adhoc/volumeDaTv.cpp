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

	int v, t; cin >> v >> t;
	int a = v;

	for (int i = 0; i < t; i++)
	{
		int ai; cin >> ai;
		a += ai;
		if (a < 0) a = 0;
		if (a > 100) a = 100;
	}

	cout << a << endl;

    return(0);
}
