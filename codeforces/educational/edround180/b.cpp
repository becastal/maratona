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
	int n, res = INF; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	for (int i = 0; i < n-1; i++) {
		int mx = a[i+1], mn = a[i+1];
		for (int j = i + 1; j < n; j++) {
			mx = max(mx, a[j]);
			mn = min(mn, a[j]);
			if (a[i] + 1 >= mn and a[i] - 1 <= mx) {
				res = min(res, j - i - 1);
			}
		}

		mx = a[i], mn = a[i];
		for (int j = i + 1; j < n; j++) {
			if (a[j] + 1 >= mn and a[j] - 1 <= mx) {
				res = min(res, j - i - 1);
			}
			mx = max(mx, a[j]);
			mn = min(mn, a[j]);
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
