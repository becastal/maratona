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

	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;

	vector<int> dp(n + 1, 0);
	for (int i = c0; i <= n; i++)
		dp[i] = max(dp[i], dp[i - c0] + d0);

	for (int i = 0; i < m; i++)
	{
		int ai, bi, ci, di;
		cin >> ai >> bi >> ci >> di;

		for (int k = 0; k < ai / bi; k++)
			for (int j = n; j >= ci; j--)
				dp[j] = max(dp[j], dp[j - ci] + di);
	}

	int res = *max_element(dp.begin(), dp.end());
	cout << res << endl;

    return(0);
}
