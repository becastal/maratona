#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<char>> A(n, vector<char>(m));

	vector<vector<int>> C(n, vector<int>(26, 0)), L(m, vector<int>(26, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			C[i][A[i][j] - 'a']++;
			L[j][A[i][j] - 'a']++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (C[i][A[i][j] - 'a'] == 1 and L[j][A[i][j] - 'a'] == 1) {
				cout << A[i][j];
			}
		}
	}
	cout << endl;

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

