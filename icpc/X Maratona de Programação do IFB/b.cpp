#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {

	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n)), useia(n, vector<int>(n+1, 0)), useib(n, vector<int>(n+1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j]) {
				useia[i][a[i][j]] = 1;
				useib[j][a[i][j]] = 1;
			}
		}
	}

	function<void(int)> f = [&](int c) {
		if (c == n*n) {
			int ok = 1;
			for (int i = 0; i < n; i++) {
				set<int> sa, sb;
				for (int j = 0; j < n; j++) {
					sa.insert(a[i][j]);	
					sb.insert(a[j][i]);	
				}
				ok &= ((int)sa.size() == n) and ((int)sb.size() == n);
			}
			
			if (ok) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						cout << a[i][j] << " \n"[j==n-1];
					}
				}
				exit(0);
			}
			return;
		}


		int i = c / n, j = c % n;
		if (a[i][j]) {
			f(c + 1);
			return;
		} else {
			for (int k = 1; k <= n; k++) {
				if (!useia[i][k] and !useib[j][k]) {
					useia[i][k] = 1, useib[j][k] = 1;
					a[i][j] = k;
					f(c + 1);

					useia[i][k] = 0, useib[j][k] = 0;
					a[i][j] = 0;
				}
			}
		}
	};

	f(0);
	cout << -1 << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
