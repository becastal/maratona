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
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	A[0][0] = '.';
	for (int i = 0, ui = 0, uj = 0; i < k; i++) {
		char c; cin >> c;

		if (c == 'U') {
			if (--ui < 0) ui = 0;
		} else if (c == 'D') {
			if (++ui >= n) ui = n-1;
		} else if (c == 'L') {
			if (--uj < 0) uj = 0;
		} else if (c == 'R') {
			if (++uj >= m) uj = m-1;
		}

		A[ui][uj] = '.';
	}

	int res = 0;
	for (auto& s : A) {
		res += count(all(s), '#');
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

