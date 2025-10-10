#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int m, n; cin >> m >> n;
	vector A(m, vector<int>());
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		A[x % m].push_back(x);
	}

	for (int i = 0; i < m; i++) {
		cout << i << " -> ";
		for (int j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << " -> ";
		}
		cout << "\\" << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
		if (t) cout << endl;
	}
    
    return(0);
}

