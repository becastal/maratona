#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct hopcroft_karp {
	int n, m;
	vector<vector<int>> g;
	vector<int> dist, nxt, ma, mb;

	hopcroft_karp(int n_, int m_) : n(n_), m(m_), g(n),
		dist(n), nxt(n), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].push_back(b); }

	bool dfs(int i) {
		for (int &id = nxt[i]; id < g[i].size(); id++) {
			int j = g[i][id];
			if (mb[j] == -1 or (dist[mb[j]] == dist[i] + 1 and dfs(mb[j]))) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	bool bfs() {
		for (int i = 0; i < n; i++) dist[i] = n;
		queue<int> q;
		for (int i = 0; i < n; i++) if (ma[i] == -1) {
			dist[i] = 0;
			q.push(i);
		}
		bool rep = 0;
		while (q.size()) {
			int i = q.front(); q.pop();
			for (int j : g[i]) {
				if (mb[j] == -1) rep = 1;
				else if (dist[mb[j]] > dist[i] + 1) {
					dist[mb[j]] = dist[i] + 1;
					q.push(mb[j]);
				}
			}
		}
		return rep;
	}
	int matching() {
		int ret = 0;
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (bfs()) {
			for (int i = 0; i < n; i++) nxt[i] = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++;
		}
		return ret;
	}
};

int solve() {
	int n; cin >> n;

	vector<int> X(n), R(n);
	vector<int> B;

	for (int i = 0; i < n; i++) {
		cin >> X[i] >> R[i];
		B.push_back(X[i] + R[i]);
		B.push_back(X[i] - R[i]);
	}

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	int m = (int)B.size();

	hopcroft_karp H(n, m);
	for (int i = 0; i < n; i++){ 
		for (int vj : {X[i] + R[i], X[i] - R[i]}) {
			int j = lower_bound(all(B), vj) - B.begin();
			H.add(i, j);
		}
	}
	cout << H.matching() << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

