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
	int n, k; cin >> n >> k;
	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	deque<pair<int, int>> Q; Q.emplace_front(0, 0);
	vector<vector<int>> D(n, vector<int>(k, INF)); D[0][0] = 0;

	while (Q.size()) {
		auto [u, su] = Q.front(); Q.pop_front();

		for (int v : G[u]) {
			int sv = (su + 1) % k, w = !sv;
			if (D[u][su] + w >= D[v][sv]) continue;

			D[v][sv] = D[u][su] + w;
			if (w) Q.emplace_back(v, sv);
			else Q.emplace_front(v, sv);
		}
	}

	for (int i = 1; i < n; i++) {
		cout << (D[i][0] == INF ? -1 : D[i][0]) << " \n"[i==n-1];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
