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

	int t; cin >> t;
	while (t--) {
		int n, a, b; cin >> n >> a >> b;
		
		int res = 0;
		if (2 * a > b) {
			res = n / 2 * b;
			n %= 2;
			res += n * a;
		} else {
			res = n * a;
		}
		cout << res << endl;
	}
    
    return(0);
}
