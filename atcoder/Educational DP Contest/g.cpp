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

const int MAX = 1e5 + 10;
vector<int> g[MAX];
int peso[MAX], d[MAX], vis[MAX];

void dfs(int u) {
	vis[u] = true;
	for (int v : g[u]) {
		d[v] = max(d[v], d[u] + 1);
		peso[v]--;
		if (!peso[v]) {
			dfs(v);
		}
	}
}

int main() {
    _;

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
		peso[b]++;
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i] and !peso[i]) {
			dfs(i);
		}
	}

	int res = 0;
	for (int i : d)
		res = max(res, i);

	cout << res << endl;
    
    return(0);
}
