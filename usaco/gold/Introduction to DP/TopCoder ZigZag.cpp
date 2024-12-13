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
	vector<int> v(n);
	for (int& i : v) cin >> i;
	vector<array<int, 2>> dp(n, {1, 1});

	int res = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i]) dp[i][0] = max(dp[i][0], dp[i][1] + 1);
			if (v[j] < v[i]) dp[i][1] = max(dp[i][1], dp[i][0] + 1);
		}
		res = max(res, dp[i][k]);
	}

	cout << res << endl;

    return(0);
}
