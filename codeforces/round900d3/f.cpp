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
// achar um coprimo a de n tal que d(a) = n/d(n)
// porque sei que d(n*a) = d(n) * d(a);

int d(ll n) {
	int res = 0;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res++;
			res += n / i != i;
		}
	}
	return res;
}

void solve() {
	ll n, q; cin >> n >> q;
	int dn = d(n), di = dn, inicio = n;

	for (int i = 0, k; i < q; i++) {
		cin >> k;

		if (k == 1) {
			int x; cin >> x; n *= x;
			dn *= d(x);

			if (n != 2 and (n % dn != 0 or dn == 2)) { cout << "no" << endl; continue; }

			// nao acho que isso daqui eh verdade. tenho que buscar um coprimo talvez.
			cout << "yes" << endl;
		} else {
			n = inicio;
			dn = di;
		}
	}
	cout << endl;
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

