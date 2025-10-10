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

	ll query(int i, int j, int ii, int jj) {
		return pre[ii][jj] - pre[ii][j-1] - pre[i-1][jj] + pre[i-1][j-1];
	}
};

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m));
	for (auto& i : a) for (auto& j : i) cin >> j;

	pre2d p(a);
    auto da = [&](int mi) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
				if (!a[i][j]) continue;
                int y1 = max(1, i+1 - mi);
                int x1 = max(1, j+1 - mi);
                int y2 = min(n, i+1 + mi);
                int x2 = min(m, j+1 + mi);
                if (p.query(y1, x1, y2, x2) >= ll(k) + 1) return 1;
            }
        }
        return 0;
    };

	int l = 0, r = max(n, m), res = -1;
	while (l <= r) {
		int mi = l + (r - l) / 2;

		if (da(mi)) {
			r = mi-1;
			res = mi;
		} else {
			l = mi+1;
		}
	}
	cout << res << endl;

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
