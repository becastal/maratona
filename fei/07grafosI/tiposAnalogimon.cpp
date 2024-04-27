// (todo) t_1907coloracaodecenarios.cpp
#include <iostream>
#include <vector>
#include <cstdio>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitados;
int contadorMonstros = 0;

void dfs(int nodo)
{
	_
	contadorMonstros++;
	visitados[nodo] = true;
	for (auto v : grafo[nodo])
	{
		if (!visitados[v]) dfs(v);
	}
}

int main()
{
	_
	int n, m;
	while (cin >> n >> m)
	{
		grafo.resize(n);
		visitados.resize(n);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b; a--; b--;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		
		int nodo;
		cin >> nodo; nodo--;
		dfs(nodo);
		cout << contadorMonstros << endl;
		grafo.clear(); visitados.clear(); contadorMonstros = 0;
	}
	return(0);
}