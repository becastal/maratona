#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int mod = 1e9 + 7;
map<ll, ll> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k = n / 2;
	if (n % 2 == 0) {
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % mod;
	} else {
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % mod;
	}
}

int main()
{
    _;

	F[0] = F[1] = 1;
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;	
		if (!n) {
			cout << 0 << endl;
			continue;
		}

		if (n == 1) {
			cout << 2 << endl;
			continue;
		}

		cout << ((f(n) + f(n+1)) % mod) << endl;
	}
    
    return(0);
}
