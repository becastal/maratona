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

void solve() {
	int n, s, m; cin >> n >> s >> m;
	int ult = 0, res = 0;
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		res = max(res, l - ult);
		ult = r;
		if (i == n - 1) res = max(res, m - r);
	}
	cout << (res >= s ? "YES" : "NO") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
