#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<vector<int>> grafos;
vector<int> indeg, ordem;
priority_queue<int, vector<int>, greater<int>> pq;

// Função para realizar a ordenação topológica em um grafo direcionado
// A função retorna true se for possível obter uma ordenação topológica válida
// Caso contrário, retorna false, indicando que o grafo contém um ciclo
// Complexidade: O(V + E), onde V é o número de vértices e E é o número de arestas
bool ordenacao_topologica(int vert) {
    int cnt = 0;

    // Adiciona todos os vértices com grau de entrada 0 na fila de prioridade
    for (int i = 1; i <= vert; i++) {
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }

    // Enquanto houver vértices na fila de prioridade
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ordem.push_back(u);
        cnt++;

        // Para cada vizinho do vértice u, decrementa o grau de entrada
        // Se o grau de entrada de algum vizinho se tornar 0, adiciona-o na fila
        for (int v : grafos[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                pq.push(v);
            }
        }
    }

    // Se a contagem de vértices processados for igual ao número de vértices
    // Significa que foi possível realizar uma ordenação topológica válida
    return (cnt == vert);
}

int main() {_
    int vert, arestas, v1, v2;

    cin >> vert >> arestas;

    grafos.resize(vert + 1);
    indeg.assign(vert + 1, 0);

    // Constrói o grafo e calcula os graus de entrada de cada vértice
    for (int j = 0; j < arestas; j++) {
        cin >> v1 >> v2;
        grafos[v1].push_back(v2);
        indeg[v2]++;
    }

    // Chama a função de ordenação topológica
    if (ordenacao_topologica(vert)) {
        // Se a ordenação for bem-sucedida, imprime a ordem topológica
        for (int u : ordem) {
            cout << u << " ";
        }
        cout << endl;
    } else {
        // Se a ordenação não for possível, imprime uma mensagem indicando o problema
        cout << "Não é possível realizar uma ordenação topológica válida." << endl;
    }

    return 0;
}

