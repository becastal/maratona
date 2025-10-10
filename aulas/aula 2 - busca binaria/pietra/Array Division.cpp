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
	int n, k; cin >> n >> k;
	vector<int> a(n);

	ll l = 0, r = 0;
	for (int& i : a) cin >> i, r += i;

	auto f = [&](ll m) {
		int sec = 1;
		ll soma = 0;

		for (int i : a) {
			if (i > m) return 0;

			soma += i;
			if (soma > m) {
				soma = i;
				sec++;
			}
		}
		return int(sec <= k);
	};

	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (f(m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << l << endl;

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
