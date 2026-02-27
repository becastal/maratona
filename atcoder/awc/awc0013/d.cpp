#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

1 2
4 6
7 1

1: 3 + 6 = 9
4: 3 = 3

2: 4 + 1 = 5
6: 5 = 5

*/

int solve() {
	int n, m, res = 0; cin >> n >> m;
	vector<vector<int>> A(m, vector<int>(n));	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[j][i];
		}
	}

	for (int i = 0; i < m; i++) {
		sort(all(A[i]));
		int agr = 0, tot = accumulate(all(A[i]), 0LL);
		for (int j = 0, p = 0; j < n; j++) {
			p += A[i][j];
			agr += ((j + 1) * A[i][j] - p) + 
					(tot - p) - (n - j - 1) * A[i][j];
		}
		res += agr >> 1;
	}
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

