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

	ll n, k; cin >> n >> k;

	auto f = [&](ll x) {
		return 4 * x * (n - x);	
	};

	ll l = 1, r = (n+1)/2;
	while (l < r) {
		ll m = (l+r)/2;

		if (f(m) <= k) {
			l = m+1;
		} else {
			r = m;
		}
	}
	ll tudo = l-1;

	k -= f(tudo);

	ll x = tudo + 1, y = tudo;
	ll passos = n - 2LL*tudo;

	vector<pair<int, int>> movs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int dir = 0;

	while (k > 0) {
		x += movs[dir].f * min(k, passos);
		y += movs[dir].s * min(k, passos);

		k -= passos;
		if (!dir) passos--;
		dir++;
	}

	cout << x << ' ' << y << endl;
    
    return(0);
}
