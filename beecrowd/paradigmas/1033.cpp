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

map<ll, ll> F;
ll f(ll n, ll mod) {
    if (F.count(n)) return F[n];
    ll k = n / 2;
    if (n % 2 == 0) {
        return F[n] = ( f(k, mod)*f(k, mod) + f(k-1, mod)*f(k-1, mod) ) % mod;
    } else {
        return F[n] = ( f(k, mod)*f(k+1, mod) + f(k-1, mod)*f(k, mod) ) % mod;
    }
}

ll fib(ll n, ll mod) {
	F.clear();
	F[0] = F[1] = 1;
	return f(n, mod);
}

int main()
{
    _;

	ll n, b, cas = 0;
	while (cin >> n >> b and b) {
		cout << "Case " << ++cas << ": " << n << ' ' << b << ' ' << (fib(n, b) + fib(n, b) - 1 + b) % b << endl;
	}
    
    return(0);
}
