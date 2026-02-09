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
		//printf("(%d, %d) (%d %d)\n", i, j, ii, jj);
		return pre[ii][jj] - pre[ii][j-1] - pre[i-1][jj] + pre[i-1][j-1];
	}
};

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<array<int, 2>> A(k);
	vector<vector<int>> B(n, vector<int>(m));

	for (auto& [a, b] : A) { 
		cin >> a >> b; a--, b--;
		B[a][b] = 1;
	} 

	pre2d P(B);

	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (!B[i][j]) {
			int l = 0, r = min(m - j - 1, n - i - 1), agr = 0;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				
				if (P.query(i + 1, j + 1, i + mid + 1, j + mid + 1)) {
					r = mid - 1;
				} else {
					l = mid + 1;
					agr = mid;
				}
			}
			res += agr + 1;
		}
	}
	cout << res << endl;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << B[i][j] << " \n"[j==m-1];
		}
	}

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

