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
	vector<int> P(n + 1);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		P[i+1] = P[i] + x;
	}

	for (int i = 0, s, l, r; i < m; i++) {
		cin >> s >> l >> r;
		cout << s + P[r] - P[l-1] << endl;
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

