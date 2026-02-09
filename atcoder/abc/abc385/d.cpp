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

	int n, m; cin >> n >> m;
	ll x, y; cin >> x >> y;
	set<pair<ll, ll>> casas;

	for (int i = 0, xi, yi; i < n; i++) {
		cin >> xi >> yi;
		casas.emplace(xi, yi);
	}

	map<char, pair<ll, ll>> movs = {
		{'U', make_pair(0, +1)},
		{'D', make_pair(0, -1)},
		{'R', make_pair(+1, 0)},
		{'L', make_pair(-1, 0)},
	};

	int res = 0;
	for (int i = 0; i < m; i++) {
		char di; cin >> di;
		ll ci; cin >> ci;
		ll nx = x + movs[di].f * ci, ny = y + movs[di].s * ci;

		if (casas.count(make_pair(nx, ny))) {
			// TODO: contar as celulas que passei por cima tambem
			casas.erase(make_pair(nx, ny));
			res++;
		}
		x = nx, y = ny;
	}

	cout << x << ' ' << y << ' ' << res << endl;

    return(0);
}
