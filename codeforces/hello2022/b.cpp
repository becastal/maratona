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
    vector<tuple<ll, ll, ll>> v(n);
    
    for (auto& [l, r, c] : v) cin >> l >> r >> c;

    ll minl = LINF, maxr = -LINF, c_minl = LINF, c_maxr = LINF;
    ll maior = -LINF, c_maior = LINF;
    for (int i = 0; i < n; i++) {
        auto [l, r, c] = v[i];

        if (r - l + 1 > maior) {
            maior = r - l + 1;
            c_maior = c;
        } else if (r - l + 1 == maior) {
            c_maior = min(c_maior, c);
        }

        if (l < minl) {
            minl = l;
            c_minl = c;
        } else if (l == minl) {
            c_minl = min(c_minl, c);
        }

        if (r > maxr) {
            maxr = r;
            c_maxr = c;
        } else if (r == maxr) {
            c_maxr = min(c_maxr, c);
        }

        if (maior >= maxr - minl + 1) {
            cout << min(c_maior, c_minl + c_maxr) << endl;
        } else {
            cout << c_minl + c_maxr << endl;
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
