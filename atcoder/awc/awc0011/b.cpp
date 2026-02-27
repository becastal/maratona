#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;
	char a, b; cin >> a >> b;

	for (int i = 0; i < n; i++) {
		string S = "";
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			S += string(k, (c == '#' ? a : b));
		}
		for (int j = 0; j < k; j++) {
			cout << S << endl;
		}
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

