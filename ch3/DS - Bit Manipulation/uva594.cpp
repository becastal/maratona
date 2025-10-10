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

	int x;
	while (cin >> x) {
		int res = ((x & 0xFF000000) >> 24) |
				  ((x & 0x00FF0000) >> 8)  |
				  ((x & 0x0000FF00) << 8)  |
				  ((x & 0x000000FF) << 24);

		cout << x << " converts to " << res << endl;
	}
    
    return(0);
}
