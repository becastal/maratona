#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<vector<int>> R(n, vector<int>(n));

	for (int i = 0, ui = 0, uj = (n - 1) / 2, k = 1; i < n * n; i++) {
		R[ui][uj] = k++;	
		
		int vi = (ui - 1 + n) % n, vj = (uj + 1) % n;
		if (!R[vi][vj]) {
			ui = vi, uj = vj;
			continue;
		}
		ui = (ui + 1) % n, uj = uj;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << R[i][j] << " \n"[j==n-1];
		}
	}

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

