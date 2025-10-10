#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	ll max_soma = -INF, min_soma = INF, max_dif = -INF, min_dif = INF;
	for (ll i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		ll soma = x + y, dif = x - y;
		max_soma = max(max_soma, soma);
		min_soma = min(min_soma, soma);
		max_dif = max(max_dif, dif);
		min_dif = min(min_dif, dif);
		cout << max(max_soma - min_soma, max_dif - min_dif) << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
