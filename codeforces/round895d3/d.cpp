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

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll res = 0;

	ll ambos = n / (x*y);
	ll sox = n / x - ambos, soy = n / y - ambos;

	res += (2 * n - sox + 1) * sox / 2;
	res -= (1 + soy - 1) * soy / 2;
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
