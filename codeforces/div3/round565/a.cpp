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
		ll x; cin >> x;

		int res = 0;
		while (x % 2 == 0) res++, x /= 2;
		while (x % 3 == 0) res += 2, x /= 3;
		while (x % 5 == 0) res += 3, x /= 5;

		cout << (x != 1 ? -1 : res) << endl;
	}
    
    return(0);
}
