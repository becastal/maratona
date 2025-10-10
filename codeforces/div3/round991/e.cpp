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
	string a, b, c;
	cin >> a >> b >> c;
	// maior subseq presente em c de alguma combinacao de a e b

	int na = (int)a.size(), nb = (int)b.size();
	vector dp(na+1, vector<int>(nb+1, INF));
	dp[0][0] = 0;

	for (int i = 0; i < na; i++) {
		dp[i+1][0] = dp[i][0] + (a[i] != c[i]);
	}
	for (int i = 0; i < nb; i++) {
		dp[0][i+1] = dp[0][i] + (b[i] != c[i]);
	}

	for (int i = 1; i <= na; i++) {
		for (int j = 1; j <= nb; j++) {
			dp[i][j] = min(dp[i-1][j] + (a[i-1] != c[i+j-1]), dp[i][j-1] + (b[j-1] != c[i+j-1]));
		}
	}
	cout << dp[na][nb] << endl;
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
