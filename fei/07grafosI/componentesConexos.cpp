// lista FEI 7: componentes conexos
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
vector<char> nodosDoComponente;

void dfs(int v)
{
	nodosDoComponente.push_back((char)(v + 'a'));
	visitado[v] = true;
	for (auto w : grafo[v])
	{
		if (!visitado[w])
		{
			dfs(w);
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
			char a0, a1;
			cin >> a0 >> a1;

			grafo[a0 - 'a'].push_back(a1 - 'a');
			grafo[a1 - 'a'].push_back(a0 - 'a');
		}

		cout << "Case #" << (i + 1) << ":" << endl;
		int componentes = 0;
		for (int j = 0; j < v; j++)
		{
			if (!visitado[j])
			{
				componentes++;
				dfs(j);
				sort(nodosDoComponente.begin(), nodosDoComponente.end());
				for (auto c : nodosDoComponente) cout << c << ",";
				cout << endl;
				nodosDoComponente.clear();
			}
		}
		cout << componentes << " connected components" << endl << endl;
		grafo.clear(); visitado.clear();
	}
}
