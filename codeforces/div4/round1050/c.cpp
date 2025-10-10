#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	int res = 0, ult = 0;
	for (int i = 0, a, b, p = 0; i < n; i++) {
		cin >> a >> b;

		int t = a - ult;
		if (t & 1) {
			if (p == b) res += max(0, t - 1);
			else res += t;
		} else {
			if (p == b) res += t;
			else res += max(0, t - 1);
		}

		p = b;
		ult = a;
	}
	res += m - ult;

	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

