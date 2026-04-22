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
	vector<int> P(m);
	for (int& i : P) {
		cin >> i;
	}

	for (int i = 0, k; i < n; i++) {
		cin >> k;

		int res = 0, p = -1;
		for (int j = 0, id; j < k; j++) {
			cin >> id; id--;
			if (res < P[id]) {
				res = P[id];	
				p = id;
	 		} else if (res == P[id]) {
				p = min(p, id);
			}
		}
		cout << p + 1 << endl;
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

