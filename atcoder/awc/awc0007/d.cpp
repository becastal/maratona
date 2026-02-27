#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, a, b; cin >> n >> a >> b;

	vector<vector<int>> A(n + 2, vector<int>(n + 2));
	vector<vector<int>> B(n + 2, vector<int>(n + 2));

	for (int i = 0, xa, ya, xb, yb; i < a; i++) {
		cin >> xa >> ya >> xb >> yb;
		A[xa][ya] += 1;
		A[xb + 1][ya] -= 1;
		A[xa][yb + 1] -= 1;
		A[xb + 1][yb + 1] += 1;
	}

	for (int i = 0, xa, ya, xb, yb; i < b; i++) {
		cin >> xa >> ya >> xb >> yb;
		B[xa][ya] += 1;
		B[xb + 1][ya] -= 1;
		B[xa][yb + 1] -= 1;
		B[xb + 1][yb + 1] += 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] += - A[i-1][j-1] + A[i-1][j] + A[i][j-1];
			B[i][j] += - B[i-1][j-1] + B[i-1][j] + B[i][j-1];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res += (A[i][j] and B[i][j]);
		}
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

