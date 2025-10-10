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

int n, m;
void solve() {
	int maxn = 0, minn = 0, tot = 0;
	vector<int> v(n+m);
	for (int& i : v) {
		cin >> i;
		maxn += max(0, i);
		minn += min(0, i);
		tot += i;
	}

	int range = (maxn-minn)+1; 
	vector<vector<int>> dp((n+m)+1, vector<int>(range));
	dp[0][abs(minn)] = 1;

	for (int i : v) {
		for (int j = n; j >= 1; j--) {
			for (int k = range-1; k >= 0; k--) {
				if (k - i >= 0 and k - i < range) {
					dp[j][k] |= dp[j-1][k-i];
				}
			}
		}
	}

	int resmin = INF, resmax = -INF;
	for (int i = 0; i < range; i++) {
		if (dp[n][i]) {
			int ii = i + minn;	
			resmax = max(resmax, ii * (tot - ii));
			resmin = min(resmin, ii * (tot - ii));
		}
	}

	cout << resmax << ' ' << resmin << endl;
}

int main()
{
    _;

	while (cin >> n >> m) {
		solve();
	}
    
    return(0);
}
