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

	const int maxn = 1e6 + 10;
	vector<int> dp(maxn, 0);

	dp[0] = 1;
	for (int i = 2020; i < maxn; i++) {
		for (int j : {2020, 2021}) {
			dp[i] |= dp[i-j];
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (dp[n] ? "yes" : "no") << endl;
	}
    
    return(0);
}
