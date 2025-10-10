#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<ll> R(n+1);
	for (int i = 0; i < m; i++) {
		int x, y, c1 = 0; cin >> x >> y;
		vector<int> A(n);
		for (int& j : A) cin >> j, c1 += (j == 1);

		if (x / (c1 + 1) >= y) c1++, A.push_back(1);
		else A.push_back(2);

		for (int j = 0; j <= n; j++) {
			R[j] += (A[j] == 1 ? x / c1 : y);
		}
	}
	for (ll i : R) cout << i << ' '; cout << endl;

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

