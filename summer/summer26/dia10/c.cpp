#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n, m; cin >> n >> m;

	vector<array<int, 2>> A(m);
	for (int i = 0; i < m; i++) {
		string S; cin >> S;
		for (int j = 0; j < n; j++) if (S[j] == '1') {
			A[i][0] |= (1LL << j);	
		}
		cin >> A[i][1];
	}

	int res = 0;
	function<void(int, int, int)> dfs = [&](int i, int mask, int c) {
		if (c == 0) {
			int certos = mask ^ ~(A[0][0]), ok = 1;
			for (int j = 0; j < m and ok; j++) {
				int a = __builtin_popcountll(A[j][0] & certos);
				int b = __builtin_popcountll(~A[j][0] & ~certos);
				ok &= (a + b) == A[j][1];
			}
			if (ok) res++;
			return;
		}

		if (i == n) return;
		dfs(i + 1, mask | (1LL << i), c - 1);
		dfs(i + 1, mask, c);
	};
	dfs(0, 0, A[0][1]);

	cout << res << endl;

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
