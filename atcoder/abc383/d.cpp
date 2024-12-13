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

const int MAX = 2e6+10;
int divi[MAX];
vector<ll> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int main()
{
    _;
	// precisa ser do tipo p1**2 * p1**2
	crivo(MAX-1);
	ll n; cin >> n;

	int res = 0;
	for (int i = 0; i < (int)primes.size(); i++) {
		ll a1 = primes[i] * primes[i];

		ll a8 = 1;
		int ok = 1;
		for (int j = 0; j < 8 and ok; j++) {
			ok &= !(a8 > n / primes[i]);
			a8 *= primes[i];
		}
		res += ok;
		
		for (int j = i + 1; j < (int)primes.size(); j++) {
			ll a2 = primes[j] * primes[j];

			if (a2 > n / a1) break;

			res++;
		}
	}
	cout << res << endl;
    
    return(0);
}
