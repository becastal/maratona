#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n, n_ = 0; cin >> n;

	vector<array<int, 3>> A(n);
	for (auto& [a, b, c] : A) {
		cin >> a >> b;
		c = n_++;
	}

	int m, m_ = 0; cin >> m;
	vector<array<int, 3>> B(m);
	for (auto& [a, b, c] : B) {
		cin >> a >> b;
		c = m_++;
	}

	sort(rall(A));
	sort(rall(B));

	vector<int> R(n);
	map<array<int, 2>, int> M;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m and B[j][0] >= A[i][0]) {
			M[{B[j][1], B[j][2]}]++;
			j++;
		}

		auto lb = M.lower_bound({A[i][1], -1});
		if (lb == M.end()) return cout << -1 << endl, 0;
		auto [par, cont] = *lb;
		auto [c, d] = par;
		R[A[i][2]] = d + 1;

		//cout << "(" << A[i][0] << ", " << A[i][1] << ") com (" << B[d][0] << ", " << B[d][1] << ")\n";
		if (--M[par] == 0) M.erase(par);
	}


	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i==n-1];
	}

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
