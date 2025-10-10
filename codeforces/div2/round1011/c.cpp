#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	// algum k tal que (a + k) & (b + k) == 0
	ll x, y, k = 0; cin >> x >> y;
	//if (x == y) return cout << -1 << endl, 0;
	vector<int> X(61), Y(61);
	for (int i = 0; i < 61; i++) {
		X[i] = (x >> i & 1);
		Y[i] = (y >> i & 1);
	}

	vector dp(61, vector<vector<int>>(2, vector<int>(2, 0)));
	vector pai(61, vector<vector<array<int, 3>>>(2, vector<array<int, 3>>(2, {-1, -1, -1})));
	dp[0][0][0] = 1;

	for (int i = 0; i < 60; i++) {
		for (int cx : {0, 1}) {
			for (int cy : {0, 1}) {
				if (!dp[i][cx][cy]) continue;
				for (int add : {0, 1}) {
					int sx = X[i] + cx + add;	
					int sy = Y[i] + cy + add;

					if ((sx & 1) & (sy & 1)) continue;
					if (!dp[i+1][sx >> 1][sy >> 1]) {
						dp[i+1][sx >> 1][sy >> 1] = 1;
						pai[i+1][sx >> 1][sy >> 1] = {cx, cy, add};
					}
				}
			}
		}
	}

	if (!dp[60][0][0]) return cout << -1 << endl, 0;
	int cx = 0, cy = 0;
	for (int i = 60; i >= 1; i--) {
		auto [cx_, cy_, add] = pai[i][cx][cy];
		if (add) k |= (1 << (i-1));
		tie(cx, cy) = pair<int, int>(cx_, cy_);
	}
	cout << k << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
