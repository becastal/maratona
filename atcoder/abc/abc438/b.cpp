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
	string A, B; cin >> A >> B;

	int res = LLONG_MAX;
	for (int p = 0; p <= n - m; p++) {
		int agr = 0;
		for (int i = 0; i < m; i++) {
			char a = A[p + i], b = B[i];
			int c = 0;
			while (b != a) {
				b = (b == '9' ? '0' : b + 1);
				c++;
			}
			agr += c;
		}
		res = min(res, agr);
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

