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
	vector<int> cor(n);
	for (int& i : cor) cin >> i, i--;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> res(n, 0);
	int ok = 0;
	
	for (int u = 0; u < n; u++) {
		map<int, int> mp;
		mp[cor[u]]++;

		for (int v : g[u]) {
			mp[cor[v]]++;
		}

		for (auto [a, b] : mp) {
			res[a] |= b >= 2;
		}
	}

	for (int i : res) cout << i; cout << endl;
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
