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

	int W, n; cin >> W >> n;
	vector<ll> w(n), v(n), c(n);
	vector<vector<pair<ll, ll>>> item(W+1);

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i] >> c[i];
		if (w[i] > W) continue;
		item[w[i]].emplace_back(v[i], c[i]);
	}

	vector<ll> dp(W+1, 0);
	for (int i = 0; i <= W; i++) {
		if (item[i].empty()) continue;
		sort(item[i].rbegin(), item[i].rend());

		int id = 0;
		for (int j = 0; j * i < W; j++) {
			if (id >= item[i].size()) break;
			
			for (int k = W; k >= i; k--) {
				dp[k] = max(dp[k], dp[k - i] + item[i][id].f);
			}
			item[i][id].s--;
			if (!item[i][id].s) id++;
		}
	}

	cout << dp[W] << endl;

    return(0);
}
