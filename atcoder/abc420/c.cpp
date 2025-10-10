#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector A(2, vector<int>(n));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	ll s = 0;
	for (int i = 0; i < n; i++) {
		s += min(A[0][i], A[1][i]);
	}

	while (q--) {
		char ci; cin >> ci;
		int p = (ci == 'B'), xi, vi; cin >> xi >> vi; xi--;

		s -= min(A[0][xi], A[1][xi]);
		A[p][xi] = vi;
		s += min(A[0][xi], A[1][xi]);
		cout << s << endl;
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

