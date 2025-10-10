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
		int n, k; cin >> n >> k;
		// bit 0, k-1 / 2  tem que ser par
		// bit 1, k-2 / 4  tem que ser par
		// bit 2, k-4 / 8  tem que ser par
		// bit 3, k-8 / 16 tem que ser par

		int res = 0;
		for (int i = 0; i < 31; i++) {
			if (k >= (1 << i) and (k - (1 << i)) / (1 << (i+1)) % 2 == 0) {
				res |= (1 << i);
			}
		}
		cout << res << endl;
	}
    
    return(0);
}
