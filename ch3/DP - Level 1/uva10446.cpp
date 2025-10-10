#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	const int B = 62, N = 62;
	vector<vector<ll>> dp(N+1, vector<ll>(B+1, 0));
	for (int i = 0; i <= B; i++) {
		dp[1][i] = dp[0][i] = dp[i][0] = 1;
	}

	for (int i = 1; i <= B; i++) {
		for (int j = 2; j <= N; j++) {
			dp[j][i] = 1;
			for (int k = 1; k <= i; k++) {
				dp[j][i] += dp[max(0, j-k)][i];
			}
		}
	}

	int cont = 1, n, b;
	while (cin >> n >> b and n <= 60) {
		cout << "Case " << cont++ << ": " << dp[max(0, n)][b] << endl;
	}
    
    return(0);
}
