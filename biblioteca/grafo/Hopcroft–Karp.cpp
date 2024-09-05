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

// Variáveis globais
int esquerda, direita, ligacoes; // Número de vértices em cada lado do grafo bipartido e número de conexões
vector<int> match, dist; // Vetores para armazenar emparelhamentos e distâncias
vector<vector<int>> g; // Lista de adjacência para o grafo

// Função para realizar a busca em largura (BFS) e encontrar caminhos alternantes
bool bfs() {
    queue<int> q;
    // Inicializa a distância de cada vértice da esquerda e coloca os vértices não emparelhados na fila
    for (int node = 1; node <= esquerda; node++) {
        if (!match[node]) {
            q.push(node);
            dist[node] = 0;
        } else {
            dist[node] = INF;
        }
    }

    dist[0] = INF; // Nó fictício que representa um emparelhamento vazio

    // Executa a BFS para encontrar caminhos aumentantes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (dist[node] >= dist[0]) { continue; }
        for (int son : g[node]) {
            if (dist[match[son]] == INF) {
                dist[match[son]] = dist[node] + 1;
                q.push(match[son]);
            }
        }
    }


    return dist[0] != INF; // Retorna true se houver um caminho aumentante
}

// Função para realizar a busca em profundidade (DFS) e encontrar um caminho aumentante
bool dfs(int node) {
    if (node == 0) { return true; } // Chegou ao nó fictício, caminho aumentante encontrado
    for (int son : g[node]) {
        if (dist[match[son]] == dist[node] + 1 && dfs(match[son])) {
            match[node] = son;
            match[son] = node;
            return true;
        }
    }
    dist[node] = INF; // Marca o nó como não acessível para evitar ciclos
    return false;
}

// Função para implementar o algoritmo de Hopcroft-Karp e encontrar o emparelhamento máximo
int hopcroft_karp() {
    int cnt = 0; // Contador para o número máximo de pares
    while (bfs()) {
        for (int node = 1; node <= esquerda; node++) {
            if (!match[node] && dfs(node)) {
                cnt++; // Conta cada novo emparelhamento encontrado
            }
        }
    }
    return cnt; // Retorna o número máximo de pares encontrados
}

int main() {
    _;

    // Leitura dos valores
    cout << "Digite o número de vértices no lado esquerdo: ";
    cin >> esquerda;
    cout << "Digite o número de vértices no lado direito: ";
    cin >> direita;
    cout << "Digite o número de conexões: ";
    cin >> ligacoes;

    g.assign(esquerda + 1, vector<int>());
    match.assign(esquerda + direita + 1, 0);
    dist.assign(esquerda + 1, 0);

    cout << "Digite as conexões (vértice da esquerda e vértice da direita):" << endl;
    for (int i = 0; i < ligacoes; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v + esquerda); // Adiciona a conexão ao grafo (ajustando o índice para o lado direito)
    }

    int resultado = hopcroft_karp(); // Calcula o número máximo de pares possíveis
    cout << "Número máximo de pares possíveis: " << resultado << endl;

    // Imprime as conexões feitas
    cout << "Pares emparelhados:" << endl;
    for (int i = 1; i <= esquerda; i++) {
        if (match[i] != 0) {
            cout << "Vértice da esquerda " << i << " está emparelhado com o vértice da direita " << match[i] - esquerda << endl;
        }
    }

    return 0;
}

