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
	function<ll(ll, ll)> f = [&] (ll l, ll r) {
		if (l == r) return l;
		int b = 63 - __builtin_clzll(r);
		ll b2 = 1LL << b;
		if (b2 <= l) return f(l - b2, r - b2) + b2;
		if ((1LL << (b + 1)) - 1 <= r) return (1LL << (b + 1)) - 1;
		return (1LL << b) - 1;
	};

	while (t--) {
		ll l, r; cin >> l >> r;
		cout << f(l, r) << endl;
	}
    
    return(0);
}
