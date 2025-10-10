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
	vector<int> a(n), b(m);

	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	vector<int> v(m, -1);
	for (int l = 0, r = 0; l < n and r < m; l++) {
		if (a[l] >= b[r]) {
			v[r++] = l;
		}
		if (r == m) return cout << 0 << endl, 0;
	}

	vector<int> v_(m, -1);
	for (int l = n-1, r = m-1; l >= 0 and r > 0; l--) {
		if (a[l] >= b[r]) {
			v_[r--] = l;
		}
	}

	int res = INF;
	for (int i = 0; i < m; i++) {
		if (i and v[i-1] == -1) continue;
		if (i+1 < m and v_[i+1] == -1) continue;

		if ((i ? v[i-1] : -1) < (i+1 < m ? v_[i+1] : n+1)) {
			res = min(res, b[i]);
		}
	}

	cout << (res == INF ? -1 : res) << endl;

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
