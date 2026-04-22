#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<int> C(n, n - 1);

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		C[a]--, C[b]--;
	}

	for (int i = 0; i < n; i++) {
		cout << C[i] * (C[i] - 1) * (C[i] - 2) / 6 << " \n"[i==n-1];
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

