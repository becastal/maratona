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
		ll i, j; cin >> i >> j;

		if (j < i) {
			if (i & 1) cout << (i-1) * (i-1) + j << endl;
			else cout << i * i - j + 1 << endl;
		} else {
			if (j & 1 ^ 1) cout << (j-1) * (j-1) + i << endl;
			else cout << j * j - i + 1 << endl;
		}
	}
    
    return(0);
}
