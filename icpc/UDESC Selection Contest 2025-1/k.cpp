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
	vector<int> a(n), b;
	for (int& i : a) cin >> i;

	int m = 0;
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		while (a[l] == a[r]) r++;

		b.push_back(a[l]), m++;
	}

	auto b_ = b;
	sort(b_.begin(), b_.end());
	for (int& i : b) i = lower_bound(b_.begin(), b_.end(), i) - b_.begin();

	vector<vector<int>> p(m);
	for (int i = 0; i < m; i++) {
		p[b[i]].push_back(i);
	}

	vector<int> dp(m, 0), mx(m, -INF);
	mx[b[0]] = 0;

	for (int i = 1; i < m; i++) {
		dp[i] = max(dp[i-1], i + mx[b[i]]);
		mx[b[i]] = max(mx[b[i]], dp[i] - i);
		//for (int j : p[b[i]]) {
		//	if (j >= i) break;
		//	dp[i] = max(dp[i], dp[j] + (i - j));
		//}
	}

	cout << m - dp[m-1] << endl;

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
