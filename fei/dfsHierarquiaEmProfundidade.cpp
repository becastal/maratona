#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
int profundidade;

void dfs(int v)
{
	visitado[v] = true;
	sort(grafo[v].begin(), grafo[v].end());
    for (auto w : grafo[v])
	{
        string nodo = to_string(v) + "-" + to_string(w);
		if (!visitado[w])
		{
			profundidade++;
			nodo += " pathR(G," + to_string(w) + ")";
			cout << nodo.insert(0, profundidade * 2, ' ') << endl;
			dfs(w);
			profundidade--;
		}
		else
		{
			cout << nodo.insert(0, (profundidade + 1) * 2, ' ') << endl;
		}
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int v, e;
		cin >> v >> e;

		grafo.resize(v); visitado.resize(v);
		for (int j = 0; j < e; j++)
		{
			int a0, a1;
			cin >> a0 >> a1;

			grafo[a0].push_back(a1);
		}
		
		cout << "Caso " << (i + 1) << ":" << endl;
		for (int j = 0; j < v; j++)
		{
            if (!visitado[j] && !grafo[j].empty())
			{
				profundidade = 0;
				dfs(j);
                cout << endl;
			}
		}
		grafo.clear();
		visitado.clear();
	}
}
