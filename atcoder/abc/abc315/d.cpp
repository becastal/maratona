#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}
	
	vector<vector<int>> Ci(n, vector<int>(26, 0)), Cj(m, vector<int>(26, 0));
	vector<int> Cci(n), Ccj(m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Cci[i] += (++Ci[i][A[i][j] - 'a'] == 1);
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			Ccj[j] += (++Cj[j][A[i][j] - 'a'] == 1);
		}
	}

	vector<vector<int>> foi(n, vector<int>(m));
	while (1) {
		vector<array<int, 2>> B;
		for (int i = 0; i < n; i++) if (Cci[i] == 1) {
			for (int j = 0; j < m; j++) if (!foi[i][j] and Ci[i][A[i][j] - 'a'] > 1) {
				foi[i][j] = 1;	
				B.push_back({i, j});
			}
		}

		for (int j = 0; j < m; j++) if (Ccj[j] == 1) {
			for (int i = 0; i < n; i++) if (!foi[i][j] and Cj[j][A[i][j] - 'a'] > 1) {
				foi[i][j] = 1;	
				B.push_back({i, j});
			}
		}

		if (B.empty()) break;
		for (auto [i, j] : B) {
			Cci[i] -= (--Ci[i][A[i][j] - 'a'] == 0);
			Ccj[j] -= (--Cj[j][A[i][j] - 'a'] == 0);
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		printf("%c%c", (foi[i][j] ? '.' : A[i][j]), (j == m - 1 ? '\n': ' '));
		//	}
		//}
	}

	int res = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res -= foi[i][j];
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

