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
	for (int& i : a) {
		cin >> i;
	}

	vector<int> a_ = a;
	sort(a_.begin(), a_.end());
	int off = 0;
	for (int i = 0; i < 4; i++) {
		off += (a_[i] < 0) * abs(a_[i]);
	}

	int N = 10010;
	vector<vector<ll>> dp(N, vector<ll>(5, 0));
	dp[off][0] = 1;

	for (int i : a) {
		for (int k = 4; k >= 1; k--) {
			for (int j = N-1; j >= 0; j--) {
				if (j + i < 0 or j + i >= N) continue;
				dp[j + i][k] += dp[j][k-1];
			}
		}
	}
	
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		if (x + off < 0 or x + off >= N) {
			cout << 0 << endl;
			continue;
		}
		cout << dp[x + off][4] << endl;
	}

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
