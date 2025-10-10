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

	auto bom = [](int x) {
		int res = 0;
		while (x) {
			res += x % 10;
			x /= 10;
		}
		return res % 4 == 0;
	};

	int a; cin >> a;
	for (int i = a; ; i++) {
		if (bom(i)) return cout << i << endl, 0;
	}
    
    return(0);
}
