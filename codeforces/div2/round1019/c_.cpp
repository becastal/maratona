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

	vector<int> v(n);
	for (int& i : v) cin >> i, i = (i <= k ? +1 : -1);

	auto a = v, b = v;
	int ok = 0;
	for (int i = 1; i < n; i++) {
		a[i] += a[i-1];
		ok |= a[i] >= 2;
	}
	for (int i = 1; i < n; i++) {
		a[i] = max(a[i], a[i-1]);
	}
	for (int i = n-2; i >= 0; i--) {
		b[i] += b[i+1];
		ok |= b[i] >= 2;
	}
	for (int i = n-2; i >= 0; i--) {
		b[i] = max(b[i], b[i+1]);
	}

	for (int i = 1; i < n-1 and ok; i++) {
		ok |= a[i] >= 0 and b[i] >= 0;
	}
	cout << (ok ? "YES" : "NO") << endl;

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
