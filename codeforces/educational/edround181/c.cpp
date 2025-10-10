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
	ll l, r; cin >> l >> r;

	int n = 4;
	vector<int> P = {2, 3, 5, 7};
	auto f = [&](ll a) {

		ll cont = 0;
		for (int i = 1; i < (1 << n); i++) {
			int p = 1;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) p *= P[j];	
			}
			cont += (__builtin_popcount(i) & 1 ? +1 : -1) * (a / p);
		};

		return a - cont;
	};
	cout << f(r) - f(l-1) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
