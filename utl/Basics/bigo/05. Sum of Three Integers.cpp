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

	int k, s; cin >> k >> s;

	int res = 0;
	for (int x = 0; x <= k; x++)
		for (int y = 0; y <= k; y++)
			if (s - (x + y) <= k and s - (x + y) >= 0)
				res++;

	cout << res << endl;

    return(0);
}
