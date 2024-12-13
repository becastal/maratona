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

const int MAX = 1e6 + 10;
int divi[MAX];
vector<int> primos;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primos.push_back(i);
		for (int j : primos) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll pow(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

int main()
{
    _;

	int n, e, c; cin >> n >> e >> c;
	crivo(MAX);

	ll p, q;
	for (int i : primos) {
		if (n % i == 0) {
			p = i, q = n / i;
		}
	}

	ll tot = (p-1)*(q-1);
	ll d = inv(e, tot); // inverso modular de e mod tot;
	ll res = pow(c, d, n); // c^d mod n;

	cout << res << endl;
    
    return(0);
}
