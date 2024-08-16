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

const int mod = 1e9 + 7;

int main()
{
    _;

	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<vector<int>> g(n);
	for (int l = 0, r = n - 1; l < r; l++, r--) {
		g[l].push_back(r);		
		g[r].push_back(l);
	}

	for (int i = 0, u, v; i < q; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<bool> vis(n, 0);
	auto dfs = [&] (int src) {
		stack<int> st; st.push(src);
		bitset<26> bs;
		if (s[src] != '*') bs[s[src] - 'a'] = 1;
		bool igual = true;
		vis[src] = 1;
		
		while (!st.empty()) {
			int u = st.top(); st.pop();
			igual &= (s[u] == s[src]);
			if (s[u] != '*') bs[s[u] - 'a'] = 1;

			for (int v : g[u]) {
				if (!vis[v]) {
					vis[v] = 1;
					st.push(v);
				}
			}
		}

		if (igual and s[src] == '*') return 26;
		if (igual and s[src] != '*') return 1;
		if (!igual and bs.count() == 1) return 1;
		return 0;
	};

	ll res = 1;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			res = (res * dfs(i)) % mod;
		}
	}
	cout << res << endl;

    return(0);
}
