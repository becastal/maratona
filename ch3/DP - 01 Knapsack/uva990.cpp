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

int W, cte;
void solve() {
	int n; cin >> n;
	vector<int> w(n), ww(n), v(n);

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		ww[i] = 3 * w[i] * cte;
	}

	vector<int> dp(W+1, 0);
	vector<vector<int>> pego(W+1);

	for (int i = 0; i < n; i++) {
		for (int j = W; j >= ww[i]; j--) {
			if (dp[j-ww[i]] + v[i] > dp[j]) {
				dp[j] = dp[j-ww[i]] + v[i];
				pego[j] = pego[j-ww[i]];
				pego[j].push_back(i);
			}
		}
	}

	int agr, melhor = -INF;
	for (int i = W; i >= 0; i--) {
		if (dp[i] > melhor) {
			melhor = dp[i];
			agr = i;
		}
	}

	cout << dp[agr] << endl;

	cout << pego[agr].size() << endl;
	for (int i : pego[agr]) {
		cout << w[i] << ' ' << v[i] << endl;
	}
}

int main()
{
    _;

	int t = 0;
	while (cin >> W >> cte) {
		if (t++) cout << endl;
		solve();
	}
    
    return(0);
}
