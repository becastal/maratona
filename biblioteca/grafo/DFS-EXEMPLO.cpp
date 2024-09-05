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

int* visitados;
void dfs(int rotulo);
vector<vector<int>> grafos;

int main() {
        int vert;
        int arestas;
        int v1, v2;
        int nodo;

        cin >> nodo;
        cin >> vert >> arestas;

        grafos.resize(vert,);
        visitados = new int[vert];
        fill_n(visitados, vert, 0);

        for (int j = 0; j < arestas; j++) {
            cin >> v1 >> v2;
            grafos[v1].push_back(v2);
            grafos[v2].push_back(v1);
        }

        dfs(nodo);

        delete[] visitados;
        grafos.clear();

        return 0;
}

void dfs(int rotulo) {
    visitados[rotulo] = 1;
    cout << rotulo << " "; // Imprime o vértice visitado

    for (int i = 0; i < grafos[rotulo].size(); i++) {
        if (visitados[grafos[rotulo][i]] == 0) {
            dfs(grafos[rotulo][i]);
        }
    }
}
