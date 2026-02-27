#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	vector<array<int, 3>> Q(k);
	for (auto& [l, r, x] : Q) {
		cin >> l >> r >> x; l--, r--;
	}

	vector<int> R(k, 1);
	auto calc = [&](int b) {
		vector<int> F(n+1, 0), X(n+1, 0);
		for (int i = 0; i < k; i++) if (Q[i][2] >> b & 1) {
			auto [l, r, x] = Q[i];

			F[l] += 1, F[r+1] -= 1;
			X[l] ^= i, X[r+1] ^= i;
		}

		for (int i = 1; i <= n; i++) {
			F[i] += F[i-1];
			X[i] ^= X[i-1];
		}

		vector<int> P(n+1, 0);
		for (int i = 1; i <= n; i++) {
			P[i] = P[i-1] + (F[i-1] > 0);
		}

		vector<int> prox(n+1), ult(n+1);


		for (int i = 0; i < k; i++) {
			R[i] &= R_[i];
		}
	};

	for (int i = 0; i < 60; i++) {
		calc(i);
	}
	
	for (int i = 0; i < k; i++) {
		cout << R[i];
	}
	cout << endl;

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

