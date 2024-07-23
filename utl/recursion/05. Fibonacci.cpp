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

	function<ll(ll)> fib = [&] (ll a) {
		if (a == 0ll) return 0ll;
		if (a == 1ll) return 1ll;
		return fib(a - 1ll) + fib(a - 2ll);
	};

	ll n; cin >> n;
	cout << fib(n - 1) << endl;
    
    return(0);
}
