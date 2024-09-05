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

	int n; cin >> n;
	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> ordem(n), reordena(n);	
	for (int i = 0; i < n; i++) {
		cin >> ordem[i]; ordem[i]--;
		reordena[ordem[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end(), [&](int a, int b) { return reordena[a] < reordena[b]; });
	}

	vector<int> vis(n, 0), res;
	function<void()> bfs = [&]() {
		queue<int> q; q.push(0);

		while(!q.empty()) {
			queue<int> temp;
			while(!q.empty()) {
				int u = q.front(); q.pop();
				res.push_back(u);
				vis[u] = 1;
				for (int v : g[u]) {
					if (!vis[v]) {
						temp.push(v);
					}
				}
			}
			q = temp;			
		}
	};
	bfs();

	bool ok = 1;
	for (int i = 0; i < n; i++) {
		ok &= (res[i] == ordem[i]);
	}
	cout << (ok ? "Yes" : "No") << endl;
    
    return(0);
}
