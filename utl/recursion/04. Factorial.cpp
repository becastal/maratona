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

	function<ll(ll)> fact = [&] (ll a) {
		if (a == 1) return 1ll;
		return a * (ll) fact(a - 1ll);
	};

	ll n; cin >> n;
	cout << fact(n) << endl;
    
    return(0);
}
