#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> C(n);
	vector<vector<int>> A(n, vector<int>(37));
	for (int i = 0; i < n; i++) {
		cin >> C[i];
		for (int j = 0, x; j < C[i]; j++) {
			cin >> x;
			A[i][x] = 1;
		}
	}

	vector<int> R;
	int X, q = INT_MAX; cin >> X;
	for (int i = 0; i < n; i++) if (A[i][X] and C[i] <= q) {
		if (C[i] < q) {
			R.clear();	
			q = C[i];
		}
		R.push_back(i);
	}

	cout << R.size() << endl;
	for (int i : R) {
		cout << i + 1 << ' ';
	}
	cout << endl;

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

