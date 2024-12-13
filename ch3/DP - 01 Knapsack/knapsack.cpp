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

	int W, n;
	while (cin >> W >> n) {
		vector<int> w(n), v(n), dp(W+1, 0);
		vector<vector<int>> esc(n, vector<int> (W+1));

		for (int i = 0; i < n; i++) {
			cin >> v[i] >> w[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = W; j >= w[i]; j--) {
				if (dp[j - w[i]] + v[i] > dp[j]) {
					dp[j] = dp[j - w[i]] + v[i];
					esc[i][j] = 1;
				}
			}
		}

		vector<int> res;

		for (int i = n-1, agr = W; i >= 0; i--) {
			if (agr >= w[i] and esc[i][agr]) {
				res.push_back(i);
				agr -= w[i];
			}
		}

		cout << res.size() << endl;
		for (int i : res) cout << i << ' '; cout << endl;
	}
    
    return(0);
}
