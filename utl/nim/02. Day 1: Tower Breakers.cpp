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
		int n, m; cin >> n >> m;
		// para uma singular torre i;

		if (m == 1 or n & 1 ^ 1) {
			cout << 2 << endl;
		} else {
			cout << 1 << endl; 
		}
	}
    
    return(0);
}
