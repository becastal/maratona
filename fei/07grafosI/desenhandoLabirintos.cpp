// lista FEI 7: desenhando labirintos
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
int tracos = 0;

void dfs(int v)
{
	visitado[v] = true;
	for (auto w : grafo[v])
	{
		if (!visitado[w])
		{
			tracos++;	
			dfs(w);
		}
	}
}

int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int nodo, vertices, arestas;
		cin >> nodo;
		cin >> vertices >> arestas;
		
		grafo.resize(vertices); visitado.resize(vertices);
		for (int j = 0; j < arestas; j++)
		{
			int o, p;
			cin >> o >> p;
			grafo[o].push_back(p);
			grafo[p].push_back(o);
		}

		dfs(nodo);
		cout << tracos * 2 << endl;
		grafo.clear(); visitado.clear(); tracos = 0;
	}
}
