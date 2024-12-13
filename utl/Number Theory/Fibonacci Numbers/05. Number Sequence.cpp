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

const int mod = 1000000;
map<ll, ll> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n % 2 == 0) {
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
	} else {
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod;
	}
}

int main()
{
    _;

	int dez[8]; dez[0] = 1;
	for (int i = 1; i < 8; i++) {
		dez[i] = dez[i-1]*10;
	}

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ll a, b, n, m;
		cin >> a >> b >> n >> m;
		F.clear();
		F[0] = F[1] = 1;
		cout << "Case " << t << ": " << (!n ? 0 : f(n-1) % dez[m]) << endl;
	}
    
    return(0);
}
