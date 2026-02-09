#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

#define int ll

const int MAXN = 1010;
const int MAXM = 50010;

int dpa[MAXN][MAXM];
int suf[MAXM], mx[MAXM];
bitset<MAXM> cur, nxt;

int solve() {
	int n, m; cin >> n >> m;
	string R(n, 'C');

	vector<int> P(n), V(n);
	for (int i = 0; i < n; i++) cin >> P[i] >> V[i];

	for (int j = 0; j <= m; j++) dpa[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			dpa[i][j] = dpa[i-1][j];
			if (j >= P[i-1]) {
				dpa[i][j] = max(dpa[i][j], dpa[i-1][j - P[i-1]] + V[i-1]);
			}
		}
	}

	int S = 0;
	for (int j = 0; j <= m; j++) {
		S = max(S, dpa[n][j]);
	}

	cur.reset();
	cur.set(m);

	for (int i = n; i >= 1; i--) {
		nxt.reset();
		for (int c = 0; c <= m; c++) if (cur.test(c)) {
			if (dpa[i][c] == dpa[i-1][c]) {
				nxt.set(c);
			}
			if (c >= P[i-1] && dpa[i][c] == dpa[i-1][c - P[i-1]] + V[i-1]) {
				R[i-1] = 'B';
				nxt.set(c - P[i-1]);
			}
		}
		cur = nxt;
	}

	for (int c = 0; c <= m; c++) suf[c] = 0;

	for (int i = n - 1; i >= 0; i--) {
		mx[0] = suf[0];
		for (int c = 1; c <= m; c++) {
			mx[c] = max(mx[c-1], suf[c]);
		}

		int s = 0;
		for (int j = 0; j <= m; j++) {
			s = max(s, dpa[i][j] + mx[m - j]);
		}

		if (s != S) R[i] = 'A';

		for (int c = m; c >= P[i]; c--) {
			suf[c] = max(suf[c], suf[c - P[i]] + V[i]);
		}
	}

	cout << R << endl;
	return 0;
}

signed main() {
	_;
	
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
