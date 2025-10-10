#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> A(n);
	vector<int> cont(m+1);
	for (int i = 0, nn; i < n; i++) {
		cin >> nn;
		A[i] = vector<int>(nn);
		for (int& j : A[i]) {
			cin >> j;
			cont[j]++;
		}
	}

	for (int i = 1; i <= m; i++) {
		if (!cont[i]) return cout << "NO" << endl, 0;
	}

	int conttudo = 0;
	for (int i = 0; i < n; i++) {
		int tudo = 1;

		for (int j = 0; j < A[i].size(); j++) {
			tudo &= cont[A[i][j]] >= 2;
		}

		conttudo += tudo;
	}
	if (conttudo >= 2) return cout << "YES" << endl, 0;
	
	cout << "NO" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

