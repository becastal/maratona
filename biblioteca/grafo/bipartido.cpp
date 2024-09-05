/*
bipartido

descricao:
	checa se o grafo eh bipartivel.

complexidade:
	o(n);
*/
function<bool(int, int)> dfs = [&](int u, int c) {
	cor[u] = c;
	for (int v : g[u]) {
		if (cor[v] == -1) {
			if (!dfs(v, !c)) {
				return 0;
			}
		}
		else if (cor[v] == c) return 0;
	}
	return 1;
};

for (int i = 0; i < n; i++) {
	if (cor[i] == -1) {
		if (!dfs(i, 1)) return cout << "IMPOSSIBLE" << endl, 0;
	}
}
