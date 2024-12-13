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

	int n; cin >> n;
	int res = INF;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		int cont = 0;
		while (x & 1 ^ 1) {
			cont++;
			x >>= 1;
		}
		res = min(res, cont);
	}
	cout << res << endl;
    
    return(0);
}
