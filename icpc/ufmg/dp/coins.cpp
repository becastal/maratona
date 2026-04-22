#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int n; cin >> n;
	vector<ld> v(n);
	for (ld& vi : v)
		cin >> vi;

	vector<ld> dp(n + 1, 0);
	dp[0] = 1.0;
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j >= 0; j--)
		{
			if (j == 0)
				dp[j] = dp[j] * (1 - v[i]);
			else
				dp[j] = dp[j] * (1 - v[i]) + dp[j - 1] * v[i];
		}

	ld res = 0.0;
	for (int i = 0; i < n + 1; i++)
	{
		int tails = n - i;
		if (i > tails)
			res += dp[i];
	}

	cout << fixed << setprecision(15) << res << endl;
    
    return(0);
}

