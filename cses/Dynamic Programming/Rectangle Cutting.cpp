#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;

int memo[550][550];

int f(int a, int b) {
	if (a < b) swap(a, b);
	if (memo[a][b] != INF) return memo[a][b];

	int& dp = memo[a][b];
	if (a == b) return dp = 0;

	for (int i = 1; i < a; i++) {
		dp = min(dp, 1 + f(a - i, b) + f(i, b));
	}
	for (int i = 1; i < b; i++) {
		dp = min(dp, 1 + f(a, b - i) + f(a, i));
	}

	return dp;
}

int solve() {
	int a, b; cin >> a >> b;
	cout << f(a, b) << endl;

	return(0);
}

int main()
{
    _;

	memset(memo, INF, sizeof(memo));

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

