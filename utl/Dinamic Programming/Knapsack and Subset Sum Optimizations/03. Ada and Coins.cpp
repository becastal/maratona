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

const int MAX = 1e6 + 10;

int main()
{
    _;
 
    int n, q; cin >> n >> q;
    vector<int> v(n);
	for (int& i : v) cin >> i;
 
	vector<bitset<MAX>> dp(n + 1); 
 
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= MAX-1; j++) {
			dp[i][j] = dp[i - 1][j];
			int ult = j - v[i - 1];
			if (ult >= 0 and dp[i - 1][ult]) {
				dp[i][j] = 1;
			}
		}
	}
    
	vector<int> pre(MAX + 1, 0);
	for (int i = 1; i <= MAX; i++) {
		pre[i] += pre[i-1];
		pre[i] += dp[n][i];
	}

	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		cout << pre[r] - pre[l-1] << endl;
	}
 
    return 0;
}
