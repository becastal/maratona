#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, res = 0; cin >> n >> k;

	map<int, int> M;
	M[0] = 1;
	for (int i = 0, x = 0, p = 0; i < n; i++) {
		cin >> x;
		res += M[(p += x) - k];
		M[p]++;
	}
	cout << res << endl;

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

