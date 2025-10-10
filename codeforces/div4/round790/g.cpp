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
	int n; cin >> n;

	vector<vector<int>> g(n);
	for (int i = 1, x; i < n; i++) {
		cin >> x; x--;

		g[i].push_back(x);
		g[x].push_back(i);
	}

	string s; cin >> s;
	vector<int> cor(n);
	for (int i = 0; i < n; i++) {
		cor[i] = s[i] == 'B';
	}

	vector<vector<int>> cont(n, vector<int>(2, 0));
	function<void(int, int)> dfs = [&](int u, int p) {
		cont[u][cor[u]] = 1;

		for (int v : g[u]) {
			if (v == p) continue;	

			dfs(v, u);
			cont[u][0] += cont[v][0];
			cont[u][1] += cont[v][1];
		}
	};
	dfs(0, -1);

	int res = 0;
	for (int i = 0; i < n; i++) {
		res += cont[i][0] == cont[i][1]; 
	}
	cout << res << endl;
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
