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
	vector<int> p(n);
	for (int& i : p) cin >> i, i--;

	int ciclo = 0;
	vector<int> vis(n, 0), res(n, -2);
	function<void(int)> dfs = [&](int u) {
		if (res[u] != -2) {
			if (res[u] == -1) {
				ciclo = 1;
				res[u] = u;
			}
			return;
		}

		res[u] = -1;

		dfs(p[u]);

		if (res[u] != -1) ciclo = 0;
		else res[u] = ciclo ? u : res[p[u]];
	};

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}

	for (int i : res) cout << i + 1 << ' '; cout << endl;

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
