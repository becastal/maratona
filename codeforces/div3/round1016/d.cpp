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

void solve() {
	int n; cin >> n;

	int q; cin >> q;
	while (q--) {
		string s; cin >> s;

		if (s == "->") {
			ll x, y; cin >> x >> y; x--, y--;
			ll d = 0;

			ll agr = 1 << n;

			for (ll i = 0, co; i < n; i++) {
				if (x < agr >> 1 and y < agr >> 1) co = 0;
				if (x >= agr >> 1 and y >= agr >> 1) co = 1;
				if (x >= agr >> 1 and y < agr >> 1) co = 2;
				if (x < agr >> 1 and y >= agr >> 1) co = 3;

				d = 4 * d + co;
				if (co == 1) {
					x -= agr >> 1;
					y -= agr >> 1;
				} else if (co == 2) {
					x -= agr >> 1;
				} else if (co == 3) {
					y -= agr >> 1;
				}

				agr >>= 1;
			}

			cout << d+1 << endl;
		} else {
			ll d; cin >> d; d--;
			vector<ll> coord(n);

			for (ll i = 0; i < n; i++) {
				coord.push_back(d % 4);
				d /= 4;
			}
			reverse(coord.begin(), coord.end());

			ll agr = 1 << n;
			ll x = 0, y = 0;
			for (ll i : coord) {
				if (i == 1) {
					x += agr >> 1;
					y += agr >> 1;
				} else if (i == 2) {
					x += agr >> 1;
				} else if (i == 3) {
					y += agr >> 1;
				} 

				agr >>= 1;
			}
			cout << x+1 << ' ' << y+1 << endl;
		}
	}
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
