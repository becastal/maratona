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

	vector<int> v = {50, 25, 10, 5, 1};

	const int maxn = 30000; 
	vector<ll> dp(maxn+1, 0);
	dp[0] = 1;

	for (int i : v) {
		for (int j = i; j <= maxn; j++) {
			dp[j] += dp[j-i];
		}
	}
	
	int n; 
	while (cin >> n) {
		if (dp[n] != 1) {
			cout << "There are " << dp[n] << " ways to produce " << n <<  " cents change." << endl;
		} else {
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
			
	}
    
    return(0);
}
