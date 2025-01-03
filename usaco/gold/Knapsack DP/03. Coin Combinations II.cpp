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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");
	const int mod = 1e9 + 7;

	int n, x; cin >> n >> x;
	vector<int> v(n);
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	for (int& i : v) cin >> i;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i-1][j];	
			int sobra = j - v[i-1];
			if (sobra >= 0) {
				dp[i][j] = (dp[i][j] + dp[i][sobra]) % mod;
			}
		}
	}
	cout << dp[n][x] << endl;

    return(0);
}
