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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int solve() {
	int n, k; cin >> n >> k;
	
	vector<int> A(n);
	for (int& i : A) cin >> i;
	for (int i = 0; i < n; i++) {
		A.push_back(A[i]);
	}

	auto calc = [&](int l, int r) {
		vector<vector<ll>> dp(k+1, vector<ll>(2*n+1, LINF));
		dp[0][r] = 0;

		for (int it = 1; it <= k; it++) {
			for (int i = l; i < r; i++) {
				ll d = 0;
				for (int j = i + 1; j <= r; j++) {
					d += A[j-1] * (j - i - 1);
					ll d_ = dp[it-1][j];

					if (d_ < LINF) d_ += d;
					dp[it][i] = min(dp[it][i], d_);
				}
			}
		}

		return dp[k][l];
	};

	ll res = LINF;
	for (int i = 0; i < n; i++) {
		res = min(res, calc(i, i + n));
	}
	cout << res << endl;

	return(0);
}

int main() {
    _;
	setIO("cbarn2");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
