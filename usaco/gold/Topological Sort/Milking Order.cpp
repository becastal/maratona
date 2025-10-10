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

	vector<vector<int>> A(m);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int j = 0, u; j < k; j++) {
			cin >> u; u--;
			A[i].push_back(u);
		}
	}

	auto da = [&](int x) -> vector<int> {
		vector<vector<int>> g(n);
		vector<int> in(n, 0);
		for (int i = 0; i < x; i++) {
			for (int j = 1; j < (int)A[i].size(); j++) {
				g[A[i][j-1]].push_back(A[i][j]);
				in[A[i][j]]++;
			}
		}

		int dag = 1;
		vector<int> vis(n, 0);
		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			for (int v : g[u]) {
				if (vis[v] == 1) {
					dag = 0;
					return;
				}
				else if (!vis[v]) dfs(v);
			}
			vis[u] = 2;
		};
		for (int i = 0; i < n and dag; i++) if (!vis[i]) {
			dfs(i);
		}

		if (!dag) return {};
		
		priority_queue<int, vector<int>, greater<>> pq;
		for (int i = 0; i < n; i++) if (!in[i]) {
			pq.push(i);
		}

		vector<int> res;
		while (pq.size()) {
			int u = pq.top(); pq.pop();
			res.push_back(u);
			for (int v : g[u]) {
				if (!--in[v]) pq.push(v);
			}
		}

		return res;
	};
	

	vector<int> res;
	int l = 1, r = m;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		auto agr = da(mid);
		if (agr.size()) {
			l = mid + 1;
			res = move(agr);
		} else {
			r = mid - 1;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] + 1 << " \n"[i == n-1];
	}

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("milkorder");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

