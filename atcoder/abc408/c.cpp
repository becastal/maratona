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
	int n, m; cin >> n >> m;
	vector<int> a(n+2, 0);

	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r;
		a[l]++;
		a[r+1]--;
	}

	for (int i = 1; i <= n; i++) {
		a[i] += a[i-1];
	}

	int res = INF;
	for (int i = 1; i <= n; i++) {
		res = min(res, a[i]);
	}
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
