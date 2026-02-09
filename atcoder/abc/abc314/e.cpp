#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<double> C(n);
	vector<int> P(n);
	vector<vector<int>> S(n);

	for (int i = 0; i < n; i++) {
		cin >> C[i] >> P[i];
		S[i] = vector<int>(P[i]);
		for (int& j : S[i]) {
			cin >> j;
		}

		C[i] *= P[i];
		erase(S[i], 0);
		P[i] = (int)S[i].size();
		C[i] /= P[i];
	}

	vector<double> E(m, 1e18);
	for (int i = m-1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			double e = 0;
			for (int x : S[j]) {
				if (i + x < m) {
					e += E[i + x];
				}
			}
			E[i] = min(E[i], C[j] + e / P[j]);
		}
	}
	cout << fixed << setprecision(10);
	cout << E[0] << endl;

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

