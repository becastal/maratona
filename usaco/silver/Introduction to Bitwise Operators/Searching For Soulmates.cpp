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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int solve() {
	ll a, b; cin >> a >> b;

	function<ll(ll, ll)> f = [&f](ll a, ll b) {
		if (a == b) return 0LL;

		if (a > b) {
			return 1 + (a & 1) + f((a + (a & 1)) >> 1, b);
		} else {
			return min(b - a, 1 + (b & 1) + f(a, b >> 1));
		}
	};
	cout << f(a, b) << endl;

	return(0);
}

int main()
{
    _;
	setIO("");

	int t; cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
