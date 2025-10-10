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
	vector<int> a(n), h(n);

	for (int& i : a) cin >> i;
	for (int& i : h) cin >> i;

	vector<ll> prea(n+1, 0), preh(n+1, 0);
	for (int i = 1; i <= n; i++) {
		prea[i] = prea[i-1] + a[i-1];
	}
	for (int i = 1; i < n; i++) {
		preh[i] = preh[i-1] + (h[i-1] % h[i] == 0);
	}
	preh[n] = preh[n-1];

	auto da = [&](int m) {
		for (int i = 0; i + m <= n; i++) {
			if (preh[i+m-1] - preh[i] >= m-1 and prea[i+m] - prea[i] <= k) {
				return 1;
			}
		}
		return 0;
	};

	int l = 1, r = n, res = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			res = m;
			l = m + 1;			
		} else {
			r = m - 1;
		}
	}

	cout << res << endl;

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
