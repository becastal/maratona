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

	int n;
	while (cin >> n) {
		int x = 1, res = 1;

		while (x % n != 0) {
			x = (10 * x + 1) % n;
			res++;
		}

		cout << res << endl;
	}
    
    return(0);
}
