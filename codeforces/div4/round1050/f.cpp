#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m = 0; cin >> n;

	vector<vector<int>> A(n);
	for (int i = 0, k; i < n; i++) {
		cin >> k;
		m = max(m, k);
		A[i] = vector<int>(k);
		for (int& j : A[i]) cin >> j;
	}
	sort(all(A));

	vector<int> R(m);
	for (int i = 0, p = 0; i < m; i++, p++) {
		if (p >= A[0].size()) {
			vector<vector<int>> B;
			for (auto& v : A) if (v.size() > p) {
				vector<int> v_(v.begin() + p, v.end());
				B.push_back(v_);
			}
			A = move(B);
			sort(all(A));
			p = 0;
		}

		R[i] = A[0][p];
	}

	for (int i : R) cout << i << ' '; cout << endl;

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

