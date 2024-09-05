/*
tree distances I

explicacao:
	distancia pro vertice mais distante pra
	cada vertice do grafo. tres dfs pra achar
	diametro (a, b) do grafo.
*/
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

	auto dfs = [&](int src, vector<int>& d) {
		stack<int> s; s.push(src);
		d[src] = 0;

		int longe = 0, onde = 0;
		while (!s.empty()) {
			int u = s.top(); s.pop();

			for (int v : g[u]) {
				if (d[v] != -1) continue;

				s.push(v);
				d[v] = d[u] + 1;
				if (d[v] > longe) {
					longe = d[v];
					onde = v;
				}
			}
		}
		return make_pair(onde, longe);
	};

	vector<int> dx(n, -1), da(n, -1), db(n, -1);
	dfs(dfs(dfs(0, dx).f, da).f, db);

	for (int i = 0; i < n; i++) {
		cout << max(da[i], db[i]) << ' ';
	}
	cout << endl;
    
    return(0);
}

