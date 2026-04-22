#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 3e5 + 10;
vector<int> Divs[MAX];

void crivo(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			Divs[j].push_back(i);
		}
	}
}

int solve() {
	int n; cin >> n;
	vector<int> Dp(n + 1, LLONG_MAX);
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		Dp[a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int d : Divs[i]) {
			int l = Dp[d], r = Dp[i / d];
			if (l != LLONG_MAX and r != LLONG_MAX) {
				Dp[i] = min(Dp[i], l + r);
			}
		}

		cout << (Dp[i] == LLONG_MAX ? -1 : Dp[i]) << " \n"[i==n];
	}

	return(0);
}

signed main()
{
    _;
	crivo(MAX-1);

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

