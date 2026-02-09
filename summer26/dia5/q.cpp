#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, c, m; cin >> n >> c >> m;

	vector<int> V(n), S(1 << n);
	vector<double> P(n);

	for (int i = 0, p; i < n; i++) {
		cin >> V[i] >> p;
		P[i] = p / 100.0;
	}

	for (int mask = 1; mask < (1 << n); mask++) {
		int b = 63 - __builtin_clzll(mask), mask_ = mask ^ (1 << b);
		S[mask] = S[mask_] + V[b];
	}

//	for (int i = 0; i < (1 << n); i++) {
//		for (int j = 0; j < n; j++) {
//			cout << (i >> j & 1);
//		}
//		cout << ": " << S[i] << endl;
//	}

	vector<vector<double>> dp((1 << n), vector<double>(c + 1, -1.0));
	// dp[mask][i]: melhor probabilidade de ja ter pago os caras em mask e i deles terem dado certo.

	function<double(int, int)> calc = [&](int mask, int cont) {
		if (S[mask] > m) return dp[mask][cont] = 0;
		if (cont >= c) return dp[mask][cont] = 1;	
		if (dp[mask][cont] != -1.0) return dp[mask][cont];

		auto& agr = dp[mask][cont];
		agr = 0;

		for (int i = 0; i < n; i++) if (!(mask & (1 << i))) {
			int mask_ = mask | (1 << i);
			if (S[mask_] > m) continue;
			agr = max(agr, P[i] * calc(mask_, cont + 1) + (1.0 - P[i]) * calc(mask_, cont));
		}
		return agr;
	};

	cout << fixed << setprecision(20) << calc(0, 0) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

