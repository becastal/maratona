#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, res = 0; cin >> n;

	map<int, map<int, int>> M;
	map<int, int> S;
	for (int i = 0, p, q; i < n; i++) {
		cin >> p >> q;
		res += S[p]++ - M[p][q]++;
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

