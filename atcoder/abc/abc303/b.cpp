#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector A(m, vector<int>(n)), vis(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			A[i][j]--;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			vis[A[i][j-1]][A[i][j]] = vis[A[i][j]][A[i][j-1]] = 1;
			//cout << A[i][j-1] + 1 << ' ' << A[i][j] + 1 << endl;
		}
	}
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res += !vis[i][j];
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

