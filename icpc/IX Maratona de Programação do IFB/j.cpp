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

int solve() {
	int n, m; cin >> n >> m;

	vector<int> dp(n+1, INF);
	vector<pair<int, int>> a;
	dp[0] = 0;

	vector<int> o(m), l(m);
	for (int& i : o) cin >> i;
	for (int& i : l) cin >> i;

	for (int i = 0; i < m; i++) {
		int agr = 1;
		while (l[i]) {
			int tira = min(agr, l[i]);
			l[i] -= tira;
			a.emplace_back(o[i] * tira, tira);
			agr <<= 1;
		}
	}

	for (auto [i, w] : a) {
		for (int j = n; j >= i; j--) {
			dp[j] = min(dp[j], dp[j-i] + w);
		}
	}

	cout << (dp[n] == INF ? -1 : dp[n]) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
