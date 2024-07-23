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

	int q; cin >> q;
	while (q--)
	{
		int n; cin >> n;

		unsigned int res = 0;
		for (int i = 0; i < 32; i++)
			if (!(n & 1 << i))
				res += 1 << i;

		cout << res << endl;
	}
	
    
    return(0);
}
