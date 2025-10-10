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

	auto mx = a, mn = a;
	for (int i = 1; i < n; i++) {
		mx[i] = max(mx[i], mx[i-1]);
	}

	vector<ll> suf(n), res(n);
	for (int i = n-1; i >= 0; i--) {
		res[i] = suf[i] = (i == n-1 ? 0 : suf[i+1]) + a[i];
		if (i) res[i] += max(0, mx[i-1] - a[i]);
	}
	reverse(res.begin(), res.end());
	for (ll i : res) cout << i << ' '; cout << endl;

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
