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
	vector<int> C(m);
	for (int& i : C) {
		cin >> i;
	}

	int res = 0;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b; a--;
		int tira = min(b, C[a]);
		C[a] -= tira;
		res += tira;
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

