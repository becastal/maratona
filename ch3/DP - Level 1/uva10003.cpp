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

void solve(int L) {
	int n; cin >> n;
	vector<int> pos(n);
	for (int& i : pos) cin >> i;
	pos.push_back(0);
	pos.push_back(L);
	
	sort(pos.begin(), pos.end());
	vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

	for (int tam = 2; tam <= n + 1; tam++) {
		for (int l = 0; l + tam <= n + 1; l++) {
			int r = l + tam;

			dp[l][r] = INF;
			for (int k = l + 1; k < r; k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + (pos[r] - pos[l]));
			}
		}
	}

	cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;
}

int main()
{
    _;

	int L;
	while (cin >> L and L) {
		solve(L);
	}
    
    return(0);
}
