#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);
	for (auto& [l, r] : A) {
		cin >> l >> r;
	}

	vector<int> Cont(n + 1);
	for (int mask = 0; mask < (1 << n); mask++) {
		int C[2] = {0, 0};
		for (int i = 0; i < n; i++) {
			C[mask >> i & 1]++;
		}
		
		int ok = 1;
		for (int i = 0; i < n and ok; i++) {
			auto [l, r] = A[i];
			int c = C[mask >> i & 1];
			ok &= l <= c and c <= r;
		}

		if (ok) {
			Cont[min(C[0], C[1])]++;
		}
	}

	for (int i = 0; i <= n; i++) {
		cout << i << ": " << Cont[i] << endl;
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

