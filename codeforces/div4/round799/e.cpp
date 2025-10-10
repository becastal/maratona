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
	int n, k; cin >> n >> k;
	vector<int> v(n), pre = {0};
	for (int& i : v) cin >> i, pre.push_back(pre.back() + i);

	if (k > pre[n]) {
		cout << -1 << endl;
		return;
	}

	int res = INF;
	for (int i = 0; i < n; i++) {
		int l = i, r = n-1, pos = -1;
		while (l < r) {
			int m = (l + r) / 2;
			if (pre[m+1] - pre[i] <= k) {
				pos = m;
				l = m+1;
			} else {
				r = m;	
			}
		}
		if (l == r and pre[l+1] - pre[i] <= k) {
			pos = l;
		}
		if (pos == -1 or pre[pos+1] - pre[i] != k) continue;
		res = min(res, n - (pos - i + 1));
	}
	cout << res << endl;
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
