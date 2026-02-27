#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	
	vector<string> E = {
		"0",
		"1",
		"00",
		"01",
		"10",
		"11",
		"000",
		"001",
		"010",
		"011",
		"100",
		"101",
		"110",
		"111",
	};

	const int MOD = 998244353;
	map<string, int> dp;
	auto ruim = [](string a) {
		return a.size() == 3 and count(all(a), '1') & 1; 
	};

	for (int i = 0, x; i < n; i++) {
		cin >> x; x &= 1;
		map<string, int> dp_ = dp;

		dp_[to_string(x)]++;
		for (auto [a, c] : dp) if (!ruim(a)) {
			string b = a + (x ? "1" : "0");

			if (b.size() > 3) b = b.substr(1);
			//cout << a << " + " << x << " -> " << b << endl;

			if (ruim(b)) continue;
			dp_[b] += dp[a];
			if (dp_[b] >= MOD) dp_[b] -= MOD;
		}
		dp = move(dp_);

	}

	int res = 0;
	for (int i = 0; i < 14; i++) if (E[i].size() > 2 and !ruim(E[i])) {
		res += dp[E[i]];
		if (res >= MOD) res -= MOD;
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

