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

int solve() {
	int n, q; cin >> n >> q;
	map<int, int> f;

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		f[-x]++;
	}

	while (q--) {
		int k, cont = 0; cin >> k;
		for (auto [a, b] : f) {
			int i = min(b, k / (-a));
			k -= (-a) * i;
			cont += i;
			if (k <= 0) break;
		}

		cout << (k <= 0 ? cont : -1) << endl;
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
