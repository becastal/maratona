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
		int x; cin >> x;

		if (__builtin_popcount(x) == 1 or ( __builtin_popcount(x+1) == 1)) {
			cout << -1 << endl;
			continue;
		}

		int res = 0;	
		for (int i = 0; i < 31 - __builtin_clz(x); i++) {
			if (x & (1 << i)) {
				res |= (1 << i);
				break;
			}
		}

		for (int i = 0; i < 31 - __builtin_clz(x); i++) {
			if (!(x & (1 << i))) {
				res |= (1 << i);
				break;
			}
		}
		
		int a = x, b = res, c = a ^ b;
		assert(a + b > c and b + c > a and a + c > b);
		cout << res << endl;
	}

	//for (int i = 2; i < 1000; i++) {
	//	int ok = 0;
	//	for (int j = 0; j < i and !ok; j++) {
	//		int a = i, b = j, c = a ^ b;

	//		if (a + b > c and b + c > a and a + c > b) {
	//			cout << a << ' ' << b << endl;
	//			//ok = 1;
	//		}
	//	}
	//	if (!ok) {
	//		cout << i << ' ' << -1 << endl;
	//		for (int j = 0; j < 31; j++) {
	//			cout << !!(i & (1 << j));
	//		}
	//		cout << endl;
	//	}
	//}
    
    return(0);
}
