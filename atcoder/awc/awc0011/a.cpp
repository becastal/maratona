#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, s, t, res = 0; cin >> n >> m >> s >> t; 
	if (s > t) swap(s, t);

	for (int i = 0, p, v; i < m; i++) {
		cin >> p >> v;
		if (p >= s and p <= t) {
			res += v;
		}
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

