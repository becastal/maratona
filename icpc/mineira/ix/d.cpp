#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct pre2d {
	int n, m;
	vector<vector<ll>> pre;

	pre2d(vector<vector<int>> a) : n(a.size()), m(a[0].size()), pre(n+1, vector<ll>(m+1)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pre[i][j] = a[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}
	}

	ll query(int i, int j, int ii, int jj) { // 1-based
		return pre[ii][jj] - pre[ii][j-1] - pre[i-1][jj] + pre[i-1][j-1];
	}
};

int solve() {
	int n, m, k, q, mxd = 0; cin >> n >> m >> k >> q;

	vector<array<int, 3>> Q(q);
	for (auto& [d, a, b] : Q) {
		cin >> a >> b >> d;
		a--, b--;
		mxd = max(mxd, d);
	}

	auto da = [&](int mid) {
		vector<vector<int>> A(n, vector<int>(m, 0));
		for (auto [d, a, b] : Q) if (d <= mid) {
			A[a][b] = 1;
		}

		//printf("mid: %d\n", mid);
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		printf("%d", A[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("\n");

		pre2d P(A);
		for (int i = 1; i + k - 1 <= n; i++) {
			for (int j = 1; j + k - 1 <= m; j++) {
				if (P.query(i, j, i + k - 1, j + k - 1) == k * k) {
					//printf("(%d, %d), (%d, %d)\n", i, j, i + k, j + k);
					return 1;
				}
			}
		}
		return 0;
	};

	int l = 0, r = mxd, res = INT_MAX;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			r = mid-1;
			res = mid;
		} else {
			l = mid+1;
		}
	}

	if (res == INT_MAX) return cout << -1 << endl, 0;
	cout << res << endl;

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

