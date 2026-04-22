#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	for (int i = 0, a, b; i < m; i++) { 
		cin >> a >> b; a--, b--;
		G[a].push_back(b);
	}

	queue<int> Q;
	vector<int> Id(n);
	for (int i = 0; i < n; i++) { 
		Id[i] = i;
		if (G[i].size() > 1) {
			Q.push(i);
		}
	}

	function<int(int)> find = [&](int a) {
		return a == Id[a] ? a : Id[a] = find(Id[a]);	
	};

	auto merge = [&](int a, int b) {
		if ((a = find(a)) == (b = find(b))) return;
		if (G[a].size() < G[b].size()) swap(a, b);

		for (int v : G[b]) {
			G[a].push_back(v);
		}
		G[b].clear();
		Id[b] = a;

		if (G[a].size() > 1) Q.push(a);
	};

	while (Q.size()) {
		int u = find(Q.front()); Q.pop();
		if (G[u].size() <= 1) continue;

		int a = find(G[u].back());
		G[u].pop_back();

		while (G[u].size() and find(G[u].back()) == a) {
			G[u].pop_back();
		}

		if (G[u].empty()) {
			G[u].push_back(a);
			continue;
		}

		int b = find(G[u].back());
		merge(a, b);

		if (G[find(u)].size() > 1) Q.push(u);
	}

	vector<int> Cor(n, -1);
	for (int u = 0, t = 1; u < n; u++) {
		int v = find(u);
		if (Cor[v] == -1) {
			Cor[v] = t++;
		}
		cout << Cor[v] << endl;
	}

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("fcolor");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

