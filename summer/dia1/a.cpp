#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;	
	vector<vector<int>> res(n, vector<int>(m, 0));

	if (n & 1 and m & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i+j)&1) continue;
				res[i][j] = 1;
			}	
		}	
	} else if (n & 1 ^ 1 and m & 1 ^ 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j&1) continue;
				res[i][j] = 1;
			}	
		}	
		res[0][1] = 1;
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i+j)&1) continue;
				res[i][j] = 1;
			}	
		}	
		res[n-1][m-1] = 1;	
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << (res[i][j] ? 'B' : 'W');
		}	
		cout << endl;
	}	

}

int main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
