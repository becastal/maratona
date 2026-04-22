#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, w; cin >> n >> w;

	vector<int> Dp(w+1, LLONG_MAX);
	Dp[0] = 0;

	auto add = [&](int a, int v) {
		for (int i = w; i >= a; i--) if (Dp[i-a] != LLONG_MAX) {
			Dp[i] = min(Dp[i], Dp[i-a] + v);
		}
	};

	for (int i = 0, l, c; i < n; i++) { 
		cin >> l >> c;
		for (int j = 1; j <= c; j <<= 1) {
			add(l * j, j);
			c -= j;
		}
		if (c) add(l * c, c);
	}

	if (Dp[w] == LLONG_MAX) Dp[w] = -1;
	cout << Dp[w] << endl;

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

