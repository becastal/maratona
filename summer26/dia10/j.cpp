#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n, m, l; cin >> n >> m >> l;

	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
	}

	vector<int> B(m), R(m + 1);
	for (int& i : B) {
		cin >> i;
	}
	vector<int> Bs(B);
	sort(all(Bs));

	for (auto [a, b] : A) {
		if (b > l) continue;
		int lb = a - (l - b), ub = a + (l - b);

		//cout << "(a: " << a << ", b: " << b << ") ";
		//cout << "[" << lb << ", " << ub << "]\n";
		int i = lower_bound(all(Bs), lb) - Bs.begin(), j = upper_bound(all(Bs), ub) - Bs.begin();
		R[i]++, R[j]--;
	}

	for (int i = 1; i <= m; i++) {
		R[i] += R[i-1];
	}
	//for (int i : R) cout << i << ' '; cout << endl;

	vector<int> P(m);
	iota(all(P), 0);
	sort(all(P), [&](int a, int b) {
		return B[a] < B[b];
	});

	vector<int> R_(m);
	for (int i = 0; i < m; i++) {
		R_[P[i]] = R[i];	
	}
	for (int i = 0; i < m; i++) {
		cout << R_[i] << endl;
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
