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
typedef pair<int, int> ii;

const int N = 20;
ii pai[1 << N][N];
int dp[1 << N][N];

int solve() {
	int n, x; cin >> n >> x;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	if (n == 1 and !x) return cout << A[0] << " -> " << A[0] << endl, 0;

	auto dist = [](string a, string b) {
		int res = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			res += a[i] != b[i];
		}
		return res;
	};

	vector<vector<int>> d(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			d[i][j] = d[j][i] = (dist(A[i], A[j]) <= x);
		}
	}

	dp[1][0] = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int u = 0; u < n; u++) {
			if (!(mask & (1 << u))) continue;

			for (int v = 0; v < n; v++) {
				if (mask & (1 << v) or !d[u][v]) continue;

				int mask_ = mask | (1 << v);
				if (dp[mask][u] + 1 < dp[mask_][v]) {
					dp[mask_][v] = dp[mask][u] + 1;
					pai[mask_][v] = ii(mask, u);
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		if (dp[(1 << n) - 1][i] != INF and d[i][0]) {
			vector<int> res = {0};
			for (ii u = ii((1 << n) - 1, i); u != ii(-1, -1); u = pai[u.f][u.s]) {
				res.push_back(u.s);
			}
			reverse(res.begin(), res.end());
			for (int j = 0; j <= n; j++) {
				cout << A[res[j]] << (j == n ? "\n" : " -> ");
			}

			return(0);
		}
	}

	cout << "impossivel" << endl;

    return(0);
}

int main()
{
    _;

	memset(dp, INF, sizeof(dp));
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			pai[i][j] = ii(-1, -1);	
		}
	}

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
