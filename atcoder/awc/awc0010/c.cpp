#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, q; cin >> n >> k >> q;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<vector<array<int, 2>>> R(n);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		R[r].push_back({l, i});
	}

	vector<int> Res(q);
	for (int i = 0, j = 0; i < n; i++) {
		if (i and abs(A[i] - A[i-1]) > k) {
			j = i;
		}
		for (auto [l, id] : R[i]) {
			Res[id] = (l >= j);
		}
	}

	for (int i : Res) {
		cout << (i ? "Yes" : "No") << endl;
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

