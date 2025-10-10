#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<int> out(n, 0);
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[v].push_back(u);
		out[u]++;
	}

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) if (!out[i]) {
		pq.push(i);
	}

	vector<int> res;
	while (pq.size()) {
		int u = pq.top(); pq.pop();
		res.push_back(u + 1);
		for (int v : g[u]) if (!--out[v]) {
			pq.push(v);
		}
	}
	reverse(all(res));

	for (int i : res) cout << i << ' '; cout << endl;

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
