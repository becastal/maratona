#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 1e9+7;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		i %= m;
	}

	vector<int> onde(2 * m);
	for (int i = 0; i < 2 * m; i++) {
		onde[i] = i % m;
	}

	int q; cin >> q;
	vector<array<int, 3>> Qi(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		Qi[i] = {l, r, i};
	}

	vector<vector<int>> dp(n, vector<int>(m, 0));
	vector<int> R(q);

	auto conv = [&](vector<int>& a, vector<int>& b) {
		int res = 0;
		for (int i = 0; i < m; i++) {
			res += a[i] * b[(m - i) % m] % mod;
		}
		res %= mod;
		return res;
	};

	function<void(int, int, vector<array<int, 3>>&)> calc = [&](int l, int r, vector<array<int, 3>>& Q) {
		if (Q.empty()) return;
		if (l == r) {
			for (auto [a, b, id] : Q) {
				R[id] = 1 + (A[a] == 0);
			}
			return;
		}
		
		int mid = (l + r) / 2;
		fill(all(dp[mid]), 0);
		dp[mid][0] = 1;
		dp[mid][A[mid]]++;

		for (int i = mid - 1; i >= l; i--) {
			dp[i] = dp[i + 1];
			for (int j = 0; j < m; j++) {
				dp[i][onde[j + A[i]]] += dp[i + 1][j];
				dp[i][onde[j + A[i]]] %= mod;
			}
		}

		fill(all(dp[mid + 1]), 0);
		dp[mid + 1][0] = 1;
		dp[mid + 1][A[mid + 1]]++;
		for (int i = mid + 2; i <= r; i++) {
			dp[i] = dp[i-1];
			for (int j = 0; j < m; j++) {
				dp[i][onde[j + A[i]]] += dp[i-1][j];
				dp[i][onde[j + A[i]]] %= mod;
			}
		}

		vector<vector<array<int, 3>>> falta(2);
		for (auto [a, b, id] : Q) {
			if (a <= mid and mid < b) {
				R[id] = conv(dp[a], dp[b]);
			} else {
				falta[b > mid].push_back({a, b, id});
			}
		}

		calc(l, mid, falta[0]);
		calc(mid + 1, r, falta[1]);
	};
	calc(0, n-1, Qi);

	for (int i : R) {
		cout << i << endl;
	}

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

