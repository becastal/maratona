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

int main()
{
    _;
    
	int n; cin >> n;
	vector<array<int, 3>> v(n), dp(n, {0, 0, 0});
	for (auto& [a, b, c] : v)
		cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
		dp[0][i] = v[0][i];

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + v[i + 1][k]);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 3; i++)
		res = max(res, dp[n - 1][i]);

	cout << res << endl;

    return(0);
}

