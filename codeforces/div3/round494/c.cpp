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
	for (int& i : a) cin >> i;

	vector<int> pre(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i-1];
	}

	double res = 0.0;
	for (int m = k; m <= n; m++) {
		for (int i = m; i <= n; i++) {
			res = max(res, ((double)pre[i] - pre[i-m]) / m);
		}
	}
	cout << fixed << setprecision(12);
	cout << res << endl;

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
