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
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	ll res = 0;
	for (int i = 0; i <= n-3; i++) {
		for (int j = i+1; j <= n-3; j++) {
			ll ak = max({a.back(), 2 * a[i], 2 * a[j]});	

			auto l = upper_bound(a.begin() + j + 1, a.begin() + n - 1, ak - (a[i] + a[j]));
			auto r = lower_bound(a.begin() + j + 1, a.begin() + n - 1, a[i] + a[j]);
			if (r > l) res += r - l;
		}
	}

	int l = 0, r = n-2;
	while (l < r) {
		if (a[l] + a[r] > a.back()) {
			res += r - l;
			r--;
		} else {
			l++;
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
