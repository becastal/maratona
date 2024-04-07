#include <iostream> 
#include <vector>   
#include <map>      
#include <algorithm>
#include <utility>  

using namespace std;

vector<vector<int>> grafo;
vector<bool> visitados;

void dfs(int nodo)
{
	visitados[nodo] = true;
	for (auto v : grafo[nodo])
	{
		if (!visitados[v]) dfs(v);
	}
}

int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;

		grafo.resize(n); visitados.resize(n);
		for (int j = 0; j < m; j++)
		{
			int x, y;
			cin >> x >> y; x--; y--;

			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}

		int componentesConexos = 0;
		for (int j = 0; j < n; j++)
		{
			if (!visitados[j])
			{
				componentesConexos++;
				dfs(j);
			}
		}
		
		cout << "Caso #" << (i + 1) << ": ";
		if (componentesConexos == 1) cout << "a promessa foi cumprida" << endl;
		else cout << "ainda falta(m) " << (componentesConexos - 1) << " estrada(s)" << endl;
		grafo.clear(); visitados.clear();
	}
}