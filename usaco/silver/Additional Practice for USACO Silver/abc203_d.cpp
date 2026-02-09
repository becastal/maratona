#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	1)
	O(nnklogk) se brutar todos os quadrados	

	O(nn) quadrados com transicao de um pra outro custando O(klogk);
	deve passar mas chato de codar.

	2)
	mas da pra fazer bb + pref2d O(nnlog(MAX));

	pra achar se tem alguma submatriz
	com soma que eu quero (-1 se for > que mid, +1, se for <=)
	esse passa com certeza
*/

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
	int n, k; cin >> n >> k;
	vector<vector<int>> A(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	auto da = [&](int m) {
		vector B(A);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i][j] = (B[i][j] <= m ? +1 : -1);
			}
		}

		pre2d P(B);
		for (int i = 0; i <= n - k; i++) {
			for (int j = 0; j <= n - k; j++) {
				if (P.query(i + 1, j + 1, i + k, j + k) >= (k & 1)) return 1;
			}
		}
		return 0;
	};

	int l = 0, r = 1e9, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			r = m - 1;
			res = m;
		} else {
			l = m + 1;
		}
	}
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

