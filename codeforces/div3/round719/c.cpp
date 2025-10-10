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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 2) {
			cout << -1 << endl;
			continue;
		}

		int agr = 1;
		vector<vector<int>> res(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + j & 1) res[i][j] = agr++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + j & 1 ^ 1) res[i][j] = agr++;
				cout << res[i][j] << " \n"[j==n-1];
			}
		}

	}
    
    return(0);
}
