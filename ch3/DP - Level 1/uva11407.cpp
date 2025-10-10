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
	const int N = 1e4+10;
	vector<int> dp(N+1, INF);
	dp[0] = 0;

	for (int i = 1; i * i <= N; i++) {
		int ii = i*i;
		for (int j = ii; j <= N; j++) {
			dp[j] = min(dp[j], dp[j-ii]+1);		
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}
    
    return(0);
}
