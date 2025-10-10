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
	vector<int> A(n), A_;
	for (int& i : A) cin >> i;

	A_ = A;
	sort(A_.begin(), A_.end());
	A_.erase(unique(A_.begin(), A_.end()), A_.end());
	auto id = [&A_] (int x) { return lower_bound(A_.begin(), A_.end(), x) - A_.begin(); };
	int m = A_.size();

	vector<vector<int>> dp(m, vector<int>(k+1, INF));
	for (int i = 0; i < m; i++) dp[i][k] = 0;

	for (int it = 0; it < n; it++) {
		vector<vector<int>> dp_(m, vector<int>(k+1, INF));
		vector<int> melhor(k+1, INF);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= k; j++) {
				melhor[j] = min(melhor[j], dp[i][j]);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = k; j >= 0; j--) {
				if (A_[i] - A_[id(A[it])] < 0) continue;
				dp_[i][j] = min(dp_[i][j], dp[i][j] + (A_[i] - A_[id(A[it])]));
				if (j < k) dp_[i][j] = min(dp_[i][j], melhor[j+1] + (A_[i] - A_[id(A[it])]));
			}
		}

		dp.swap(dp_);
	}

	int res = INF;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= k; j++) {
			res = min(res, dp[i][j]);
			//cout << dp[i][j] << " \n"[j == k];
		}
	}
	cout << res << endl;

	return(0);
}

int main() {
    _;
	setIO("snakes");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
