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

void solve() {
	int n, m; cin >> n >> m;
	int minR, maxR, minC, maxC, sz, res;
	vector<int> r(n + 5), c(m + 5), freer(n + 5), freec(m + 5);

	vector<vector<char>> mp(n, vector<char>(m));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];

			if (mp[i][j] == '.') {
				freer[i]++;
				freec[j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dfs(i, j);
			
		}
	}

}

int main()
{
    _;
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
