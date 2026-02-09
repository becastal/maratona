#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	int C[110][110];
	memset(C, 0, sizeof(C));

	for (int i = 0, a, b, c, d; i < n; i++) {
		cin >> a >> b >> c >> d;
		for (int x = a; x < b; x++) {
			for (int y = c; y < d; y++) {
				C[x][y]++;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			res += !!C[i][j];
		}
	}
	cout << res << endl;

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

