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

	// menor ciclo. se maior que k, fazer 1
	// pra 1 eu acho que so bfs mas eu pego ou todos os pares ou todos os impares de distancia.
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;	

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int tam_ciclo = INF;
	vector<int> d(n, -1), ciclo;
	auto bfs = [&](int in) {
		d[in] = 0;
		queue<int> q; q.push(in);
		vector<int> pai(n, -1);

		while (q.size()) {
			int u = q.front(); q.pop();

			for (int v : g[u]) {
				if (d[v] != -1) {
					if (d[u] + d[v] + 1 < tam_ciclo) {
						tam_ciclo = d[u] + d[v] + 1;

						ciclo.clear();
						for (int x = u; x != -1; x = pai[x]) {
							ciclo.push_back(x+1);	
						}
						reverse(ciclo.begin(), ciclo.end());

						for (int x = v; x != -1; x = pai[x]) {
							ciclo.push_back(x+1);	
						}
					}

					continue;
				}

				d[v] = d[u] + 1;
				pai[v] = u;
				q.push(v);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		bfs(i);
	}
    
	if (tam_ciclo > 2 and tam_ciclo <= k) {
		cout << 2 << endl;
		cout << tam_ciclo << endl;
		for (int i : ciclo) cout << i << ' '; cout << endl;
	} else {
		cout << 1 << endl;

		vector<int> cont(2, 0);
		for (int i = 0; i < n; i++) {
			cont[d[i]&1]++;
		}

		int quero = cont[1] >= cont[0];
		for (int i = 0; i < n; i++) {
			if (d[i]&1 == quero) {
				cout << i+1 << ' ';
			}
		}
		cout << endl;
	}

    return(0);
}
