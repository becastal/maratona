#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k, t; cin >> n >> m >> k >> t;
	vector<int> A(n);
	for (int i = 0, p; i < m; i++) {
		cin >> p; p--;
		A[p]++;
	}

	vector<int> P(n + 1);
	for (int i = 0; i < n; i++) {
		P[i+1] = A[i] + P[i];
	}

	for (int i = 0, l, r; i < k; i++) {
		cin >> l >> r;
		cout << (P[r] - P[l-1] >= t ? "YES" : "NO") << endl;
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

