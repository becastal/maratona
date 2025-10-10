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

	vector<int> v = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

	const int maxn = 30000;
	vector<ll> dp(maxn+1, 0);
	dp[0] = 1;

	for (int i : v) {
		for (int j = i; j <= maxn; j++) {
			dp[j] += dp[j-i];
		}
	}

	double n;
	while (cin >> n and n != 0.0) {
		int ni = round(n * 100.0);
		cout << setw(6) << fixed << setprecision(2) << n << setw(17) << dp[ni] << endl;
	}
    
    return(0);
}
